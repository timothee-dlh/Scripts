/*
To Do :
Remove all printf statements for the final version ( not needed)
Error : main.c:81:17: error: label ‘nextFile’ used but not defined
*/
#include "stdio.h"
#include "dirent.h"
#include "errno.h"
#include "string.h"

void removePointDir(char* filename);
int main(int argc, char* argv[]){

      struct iterLoop {
      int MAX_CHAR, MAX_FILES;
      int iterFiles, iterChar;
      }iter;
     
      struct iterLoop *pIter = &iter;

      iter.MAX_CHAR = 300; iter.MAX_FILES = 1000;

      struct dirent *pDirent;
	  DIR *pDir; 
      
	  char* filename;
      char extension [10]; // extension of file
       
      if (argc != 2){
            printf("Please specify the directory name in argument");
            return 1;
      }

      pDir = opendir (argv[1]); // open directory
      if (pDir == NULL){
            printf("Cannot open the directory\n");
            return 1;
      }
      
      while ((pDirent = readdir(pDir)) != NULL && pIter->iterFiles < pIter->MAX_FILES ){
            filename = pDirent->d_name;
            
            while (*filename != '\0' && iter.iterChar < iter.MAX_CHAR){
                        if(strcmp(filename, ".") != 0 && strcmp(filename, "..") != 0){
						(void)printf("%c", *filename);
                       
							if(*filename == '.'){
						
								(void)printf("point detected\n");
								filename ++; 
							
								for (int i = 0; *filename != '\0' || *filename == ' '; i ++){
                                   extension[i] = *filename;
                                   (void)printf("%c", extension[i]);
                                   filename ++;
                               }              
							} 
						}else{
							goto nextFile;
						}
                  // Extension stored in  char extension [10];
                  pIter->iterChar ++; filename ++;
				
				  for(int i; i <= strlen(extension); i++){ // Reset of char extension [10];
				  strcpy(extension, "");
                  }
            }
                  
            (void)printf("\n"); 
nextFile:     // goto if not a file
            
			pIter->iterFiles ++, pIter->iterChar = 0; // next file
      }
      if(closedir(pDir) != 0){
            printf("Can't close the directory");
            return 1;
      }
      
	  return 0;
}
