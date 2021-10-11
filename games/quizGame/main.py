from question_model import Question
from data import question_data
from quiz_brain import QuizBrain



print("Welcome to the Quiz Game")
print("Need to give 12 True or False answers! Let's go and test your knowledge ")
question_bank=list()
for question in question_data:
    text = question["text"]
    answer = question["answer"]
    new_question=Question(text,answer)
    question_bank.append(new_question)

quiz_brain=QuizBrain(question_bank)
while quiz_brain.still_has_question():
    quiz_brain.next_question()

print("You have completed the quiz ")
print(f"Your Final Score is {quiz_brain.score}/12 ")
