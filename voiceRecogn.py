import speech_recognition as sr 
    
def voice_recognition(phrases):

    #Initialize the recognizer 
    r = sr.Recognizer() 

    #generate a list of all audio cards/microphones 
    mic = sr.Microphone()  

    with mic as source: 
        #wait for a second to let the recognizer adjust the  
        #energy threshold based on the surrounding noise level 
        #r.adjust_for_ambient_noise(source) 
        
        print("Say Something")

        #listens for the user's input 
        audio = r.listen(source) 
            
        try: 
            text = r.recognize_google(audio) 
            print("you said: " + text)
            
            for word in PHRASES:
                data = word.split() #split string into a list
                for temp in data:            
                    if temp == word:
                        print("You made it!!")
                        return temp
                    else:
                        pass

          
        #error occurs when google could not understand what was said 
          
        except sr.UnknownValueError: 
            print("Google Speech Recognition could not understand audio") 

        except sr.RequestError as e: 
            print("Could not request results from Google Speech Recognition service; {0}".format(e)) 
                                  
if __name__ == "__main__":
    PHRASES = ["happy", "sad", "angry"]
    voice_recognition(PHRASES)
    
     

    

















