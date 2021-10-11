class QuizBrain :
    # question_list=[]
    def __init__(self,q_list) :
        self.question_count=0
        self.question_list=q_list
        self.score=0

    def next_question(self):
        question=self.question_list[self.question_count]
        self.question_count+=1
        user_answer=input(f"Q.{self.question_count}: {question.text}(True/False)?:")
        self.check_answer(user_answer,question.answer)


    def still_has_question(self):
        if len(self.question_list)==self.question_count:
            return False
        else:
            return True

    def check_answer(self,user_answer,question_answer):
        if user_answer.lower()==question_answer.lower():
            print("You got it right!")
            self.score+=1
        else:
            print("That's wrong.")
        print(f"The correct answer was: {question_answer}.")
        print(f"Your current score is: {self.score}/{self.question_count}")
        print("\n")     
 
