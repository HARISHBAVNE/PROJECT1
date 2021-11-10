#==============================================================================
#
#Project name: File Generator.                                                      
# Input: 	   Directory,extension for file generation.
# Output:	   File genere with given extension in given directory.
# Description: It is used to create files with given extension.
# Date:		   28-05-2021
# Author nmae: HARISH VIJAY BAVNE
#
#==============================================================================

#==================
# IMPORTS MODULE.
#==================
from sys import *
import os 
from pathlib import Path

#==================================================
# FUNCTION FOR CREATING FILE WITH GIVEN EXTENSION.
#==================================================
def FileGen(directory,ext):
    if not os.path.exists(directory):
        os.mkdir(directory)
    l = 0
    for Folder,subfolder,files in os.walk(directory):
        l = len(files)
    #=======================================
    # FILE GENERATION FOR JAVA PROGRAMMING.
    #=======================================
    if (ext == ".java"):
        path = os.path.join(directory,"Program"+str(l)+ext)
        
        FileBaseName = os.path.basename(path)               #FILE NAME WITH EXTENTION.
        FileName = Path(FileBaseName).stem                  #FILE NAME WITHOUT EXTENSION.
        print(path)
        fd =  open(path,'a')
        data = (f"class {FileName}")
        fd.write(data)
        data1 = ("\n{\n,    public static void main(String arg[])\n,    {\n,    }\n,}").split(",")
        for line in data1:
            fd.write(line)
        fd.close()
    
    #============================================
    # FILE GENERATION FOR C AND CPP PROGRAMMING.
    #============================================
    elif(ext == ".c")or(ext == ".cpp"):
        path = os.path.join(directory,"Program"+str(l)+ext)
        FileBaseName = os.path.basename(path)               #FILE NAME WITH EXTENTION.
        FileName = Path(FileBaseName).stem                  #FILE NAME WITHOUT EXTENTION.
        print(path)
        fd =  open(path,'a')
        data = ("int main()\n,{\n\n,    return 0;\n,}").split(",")
        for line in data:
            fd.write(line)
        fd.close()
    elif (ext == ".py"):
        path = os.path.join(directory,"Program"+str(l)+ext)
        FileBaseName = os.path.basename(path)               #FILE NAME WITH EXTENTION.
        FileName = Path(FileBaseName).stem                  #FILE NAME WITHOUT EXTENTION.
        print(path)
        fd = open(path,'a')
        data = ('def main():\n  pass\n\nif __name__ =="__main__":\n   main()')
        for line in data:
            fd.write(line)
        fd.close()
    else:
        print("Please provide extension from:(.java) or (.c) or (.cpp)")
        
        
#================
# STARTER(MAIN)
#================
def main():
    print(f"Progeam name is:{argv[0]}")
    if (len(argv)<2):
        print("Insufficient arguments")
        exit()
    if (argv[1]=='-u') or (argv[1]=='-U'):
        print("Usage:This is use to create files with given extension")
        exit()
    if (argv[1]=='-h') or (argv[1]=='-H'):
        print("Help:provide directory and extension to create file")
        exit()
    FileGen(argv[1],argv[2])
#================
# CALL TO MAIN.
#================
if __name__ == "__main__":
    main()
