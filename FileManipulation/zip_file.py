#Import libraries
from pathlib import Path
import zipfile
import os


def backup(filepath: str):
    filename_ext = os.path.basename(filepath)
    filename = Path(filepath).stem

    zip_filename = filename + ".zip"
    print(zip_filename)

    backup_zip = zipfile.ZipFile(zip_filename, "w")

    backup_zip.write(filename_ext)

    backup_zip.close()
    print(backup_zip.namelist())

#Backup File
backup("/home/nvombat/Downloads/kaggle_data.csv")