#Prints the contents of all the files in a directory
#Import libraries
from pathlib import Path
import subprocess
import glob
import os

#View the files in the directory given in the path 
#os.listdir("PATH")

#Access the path of the current directory using pwd command
output_path = subprocess.getoutput("pwd")
print("PATH:", output_path)

#Access and store all the contents of the directory mentioned in the path in a list
files = glob.glob(output_path+"/*")
#print(files)

#If the list is not empty
if len(files) != 0:
    #For each file
    for file in files:
        #Access the file name
        file_name = Path(file).name
        print(file_name)
        try:
            #Call 'cat' command on each file and thus read the contents of each file
            subprocess.check_call(["cat", file_name])
        #If file can't be read
        except:
            #Error message
            print("Cant read " + file_name + "!")