#Import libraries
from pathlib import Path
import send2trash
import zipfile
import shutil
import os

#Path of file
p = Path('test.txt')
#Reads the text from the file and stores it in a variable
file_content = p.read_text()
print(file_content)
#This overwrites the entire file
# p.write_text('Hello, world!')

#Opens file in read-write mode returning a file handle
with open('test.txt', 'r+') as f:
    #Reads the content into a variable
    content = f.read()
    #Since after reading file pointer is at the end we shift the pointer back to the start
    f.seek(0)
    #Read file line by line and store in list
    line_content = f.readlines()
    #Display content
    print(content)
    print(line_content)
    #Close file
    f.close()

#Copy file from source to destination anbd rename copied file
path_source = Path("/home/nvombat/Desktop/Security-Fundamentals/FileManipulation")
path_dest = Path("/home/nvombat/Desktop/Security-Fundamentals/FileManipulation/copy.txt")
#shutil.copy(path_source/'test.txt', path_dest)

#Copies an entire directory and its sub directories
dir_path_source = Path("/home/nvombat/Desktop/Security-Fundamentals/FileManipulation/TestDir")
dir_path_dest = Path("/home/nvombat/Desktop/Security-Fundamentals/FileManipulation/TestDirBackup")
#shutil.copytree(dir_path_source, dir_path_dest)

#Moves a file from one folder to another
mov_path_source = "/home/nvombat/Desktop/Security-Fundamentals/FileManipulation/test.txt"
mov_path_dest = "/home/nvombat/Desktop"
#shutil.move(mov_path_source, mov_path_dest)

#To remove files & directories
os.unlink("PATH_TO_FILE")
os.rmdir("PATH_TO_DIR")
shutil.rmtree("PATH_TO_DIR")
send2trash.send2trash("PATH_TO_FILE") #SAFE DELETION

#Prints the walk of a directory
for folder_name,sub_folders,file_names in os.walk('/home/nvombat/Desktop/Security-Fundamentals'):
    print('Current Folder: ' + folder_name)
    for subfolder in sub_folders:
        print('Subfolders: ' + subfolder)
    for filename in file_names:
        print('Filenames: ' + filename)

#ZIP FILES:
#Get path to zip file
zip_path = Path.home()/'Desktop/Security-Fundamentals/FileManipulation'
print(zip_path)
#Create a zip file object where the zip file is located
eg_zip = zipfile.ZipFile(zip_path/'test.zip')
#Get the list of items in the zip file
print(eg_zip.namelist())
#Get information on a particular file
info = eg_zip.getinfo('runtime.txt')
print(info)
#Get the file sizes
print(info.file_size)
print(info.compress_size)
#Extract specific file
#eg_zip.extract('FILENAME')
#Extract all contents of the zipfile
#eg_zip.extractall()
#Close ZipFile object
eg_zip.close()

#Creates a ZipFile object to create a new zipfile in write mode -> 'a' for append
new_zip = zipfile.ZipFile('test_new.zip', 'w')
#Write a file and compress to zip
new_zip.write('test.txt', compress_type=zipfile.ZIP_DEFLATED)
new_zip.close()