#Import libraries
from pathlib import Path
import zipfile
import os

'''
Function backs up content of folder into zip file
If changes are made in folder then creates a new zipfile 
Excludes older zip files from the back up
'''
def backup(folder):
    folder = os.path.abspath(folder)
    print(folder)

    cnt=1
    while True:
        zip_filename = os.path.basename(folder)+"_backup_"+str(cnt)+".zip"
        if not os.path.exists(zip_filename):
            break
        cnt += 1
    print(zip_filename)

    #Create backup zip file in write mode
    backup_zip = zipfile.ZipFile(zip_filename, "w")
    #Walk the directory that is to be backed up
    for folder_name,sub_folders,file_names in os.walk(folder):
        #Add its contents to the zip file
        backup_zip.write(folder_name)
        for filename in file_names:
            base = os.path.basename(folder)+'_'
            #Ignore any zip files with current folder name
            if filename.startswith(base) and filename.endswith('.zip'):
                continue
            else:
                backup_zip.write(os.path.join(folder_name, filename))

    backup_zip.close()
    print(backup_zip.namelist())

#Backup Folder
backup("FileManipulation")