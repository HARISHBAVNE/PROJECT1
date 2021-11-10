from sys import *
import os
import hashlib
def CalculateCheckSym(path,blocksize = 1024):
    fd = open(path,'rb')
    hobj = hashlib.md5()
    
    buffer = fd.read(blocksize)
    while(len(buffer) > 0):
        hobj.update(buffer)
        buffer = fd.read(blocksize)
        
    fd.close()
    
    return hobj.hexdigest()

def DirectoryTraversal(path):
    print("Contents of directory are")
    duplicate = {}
    
    for Folder,Subfolder,Filename in os.walk(path):
        print("Directory name is:"+Folder)
        
        for sub in Subfolder:
            print("Subfolder of"+Folder+"is "+sub)
        for file in Filename:
            print("File name is: "+file)
            actualpath = os.path.join(Folder,file)
            hash = CalculateCheckSym(actualpath)
            print(hash)
            
            if hash in duplicate:           #that checksum is already present
                duplicate[hash].append(actualpath)            
            else:                           # there is no such checksum
                duplicate[hash] = [actualpath]
                
    return duplicate
    
def DisplayDuplicate(duplicate):
    output =list(filter(lambda x:len(x)>1,duplicate.values()))
    
    if (len(output)>0):
        print("There are duplicate files")
    else:
        print("There are no duplicate files")
        return
    icnt = 0
    i = 0
    for result in output:
        print(result)
        icnt = 0
        for path in result:
            icnt += 1
            if icnt >=2:
                print("%s"%path)
                i += 1
                os.remove(path)
    print(f"Number of removed duplicate files:{i}")
    
def main():
   print("Marvellous infosysytems")
   print("Directory traveesal script")
   
   
   if (len(argv)!=2):
      print("Error:Invalid number of arguments")
      exit()
   if (argv[1]=="-h") or (argv[1]=="-H"):
      print("It is a directory cleaner script")
      exit()

   if (argv[1]=="-u") or (argv[1]=="-U"):
      print("Usage:Provide absolute path of target directory")
      exit() 
   arr = {}
   arr = DirectoryTraversal(argv[1])

   DisplayDuplicate(arr)
if __name__ == "__main__":
    main()
