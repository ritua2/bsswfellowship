import os
import time
import pickle

saved_dump = "ckptfile.pickle"

def main(start=0):
    #some useful code before this line

    global saved_dump

    a = start
    while 1:
        time.sleep(1)
        a += 1
        print(a)
        with open(saved_dump, 'wb') as f:
                pickle.dump(a, f)


if __name__ == '__main__':
    print("For testing, interrupt the running code by typing ctrl+c")
    while 1:
       if os.path.exists(saved_dump):
        with open(saved_dump, "rb") as f:
                start = pickle.load(f)
       else:
        start = 0
       try:
            main(start=start)
       except KeyboardInterrupt:
            resume = raw_input('Would you like to continue running the code? Type the letter y for yes.')
            if resume != 'y':
                break
