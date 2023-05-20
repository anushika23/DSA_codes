import nltk
from nltk.corpus import movie_reviews
from nltk import FreqDist, classify, NaiveBayesClassifier
from nltk.tokenize import word_tokenize
import random

# Load the movie reviews dataset
#nltk.download('movie_reviews')

# Prepare the dataset
documents = [(list(movie_reviews.words(fileid)), category)
             for category in movie_reviews.categories()
             for fileid in movie_reviews.fileids(category)]

# Shuffle the documents
random.shuffle(documents)

# Rest of the code remains the same
# ...

# Extract features from the documents
all_words = FreqDist(w.lower() for w in movie_reviews.words())
word_features = list(all_words)[:2000]

def document_features(document):
    document_words = set(document)
    features = {}
    for word in word_features:
        features[word] = (word in document_words)
    return features
featuresets = [(document_features(d), c) for (d, c) in documents]

# Split the dataset into training and testing sets
train_set = featuresets[:1500]
test_set = featuresets[1500:]

# Train the Naive Bayes classifier
classifier = NaiveBayesClassifier.train(train_set)

# Define a sample text
text = "I love this movie."

# Tokenize the sample text
tokens = word_tokenize(text.lower())

# Extract features from the tokens
features = document_features(tokens)

# Perform sentiment analysis using the trained classifier
sentiment = classifier.classify(features)

# Print the sentiment
print("Sentiment:",sentiment)