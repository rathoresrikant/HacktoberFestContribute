### Live Twitter Sentiment Analysis ###

# pip install tweepy
# pip install textblob

# Creating Account with Twitter API

## Importing the Libraries ##
from textblob import TextBlob
import sys
import tweepy
import matplotlib.pyplot as plt

## Define a function to calculate the percentage ##
def percentage(part, whole):
    return 100 * float(part)/float(whole)

## Connecting with the Twitter API ##
    
# Importing the keys #
consumerKey = "copy here your keys"
consumerSecret = "copy here your keys"
accessToken = "copy here your keys"
accessTokenSecret = "copy here your keys"

# Establish the connection with API #
auth = tweepy.OAuthHandler(consumerKey, consumerSecret)
auth.set_access_token(accessToken, accessTokenSecret)
api = tweepy.API(auth)

# Search for the Term and define number of tweets #
searchTerm = input("Enter Keyword/Tag to search about: ")
NoOfTerms = int(input("Enter how many tweets to search: "))

# Get no of tweets and searched term together #
tweets = tweepy.Cursor(api.search, q=searchTerm).items(NoOfTerms)


## Iterate and Analyse the tweets ##

# Working of the TextBlob #
a = TextBlob("I am a bad Cricket player")
a.sentiment.polarity

b = TextBlob("I am a good Cricket player")
b.sentiment.polarity

c = TextBlob("I am a Cricket player")
c.sentiment.polarity

# Create variables to hold the average polarity #

positive = 0
negative = 0
neutral = 0
polarity = 0

for tweet in tweets:
   analysis = TextBlob(tweet.text) 
   polarity += analysis.sentiment.polarity
   
   if(analysis.sentiment.polarity == 0):
       neutral += 1
       
   elif(analysis.sentiment.polarity < 0.00):
       negative += 1

   elif(analysis.sentiment.polarity > 0.00):
       positive += 1

# Generate the percentages using previously created function percentage #
positive = percentage(positive, NoOfTerms)
negative = percentage(negative, NoOfTerms)
neutral  = percentage(neutral, NoOfTerms)
polarity  = percentage(polarity, NoOfTerms)

# Limit the decimal upto 2 places #
positive = format(positive, '.2f')
negative = format(negative, '.2f')
neutral = format(neutral, '.2f')


## Print the result ##

print("How people are reacting on " + searchTerm + 
      " By analyzing" + str(NoOfTerms) + " Tweets ")

if (polarity == 0):
    print("Neutral")
    
elif (polarity < 0.00):
    print("Negative")
    
elif (polarity > 0.00):
    print("Positive")

## Print the Pie Chart ##
    
labels = ['Positive ['+str(positive)+'%]', 
          'Neutral ['+str(neutral)+'%]', 
          'Negative ['+str(negative)+'%]']

sizes = [positive, neutral, negative]
colors = ['yellowgreen', 'gold', 'red']
patches, texts = plt.pie(sizes, colors = colors, startangle = 90)
plt.legend(patches, labels, loc = "best")
plt.title('How people are reacting on  '
          +searchTerm+' by analyzing '
          +str(NoOfTerms)+' Tweets ')
plt.axis('equal')
plt.tight_layout()
plt.show()