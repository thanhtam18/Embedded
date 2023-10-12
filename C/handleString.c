#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"

void capitalWords(char string[]){
    while(*string != '\0'){
        if(*string == '.'){
            string++;
            while(*string != '\0'){
                if(*string != ' '){
                    *string -= 32;
                }
                string++;
            }  
        }
        else{
            string++;
        }
    }  
}

void findWords(const char string[], char words[]){
    uint8_t length = 0;
    uint8_t count = 0;
    uint8_t location = 0;
    bool check = false;
    printf("Text: %s\r\n",words);
    for(uint8_t i = 0; words[i] != '\0'; i++)
        length++;
    while (*string != '\0')
    {
        location++;
        if(*string == words[count]){
            count++;
            string++;
            if(count == length){
                if((*string == ' ' || *string == '.') && (*(string - length -1) == ' ') || location - count == 0){
                    if(check == false){
                        check = true;
                        printf("Ket qua: Co\r\n");
                        printf("Vi tri: ");
                    }
                    printf("%d ",location - count);
                } 
                count = 0;           
            }
        }
        else{
            string++;
            count = 0;
        }                      
    }
    if(check == false)
        printf("Ket qua: Khong");
    printf("\r\n------------------\r\n");
}

void replaceString(char string[], char words[], char replaceWords[]){
    uint8_t index = 0;
    uint8_t lengthWords = 0;
    uint8_t lengthReplaceWords = 0;
    uint8_t lengthString = 0;
    uint8_t lengthStringUpdate = 0;
    uint8_t locationStart = 0;
    uint8_t locationEnd = 0;
    for(uint8_t i = 0; words[i] != '\0'; i++)
        lengthWords++;
    for(uint8_t i = 0; replaceWords[i] != '\0'; i++)
        lengthReplaceWords++;
    for(uint8_t i = 0; string[i] != '\0'; i++)
        lengthString++;       
    lengthStringUpdate = lengthString;
    for(uint8_t i = 0; string[i] != '\0'; i++){
        if(string[i] == words[index]){
            index++;
            if (index == lengthWords)
            {
                locationStart = i - index + 1;
                locationEnd = locationStart + lengthReplaceWords - 1;
                index = 0;
                lengthStringUpdate += (lengthReplaceWords - lengthWords);
                if(lengthWords > lengthReplaceWords){
                    for(uint8_t j = i + 1; string[j] != '\0'; j++){
                        string[locationEnd+ 1 + j - (i+1)] = string[j];                           
                    }
                    string[lengthStringUpdate ] = '\0';
                    for(uint8_t i = 0; i < lengthReplaceWords; i++)
                        string[i + locationStart] = replaceWords[i];               
                }
                else if(lengthWords < lengthReplaceWords){
                    for(uint8_t i = lengthStringUpdate; i != locationEnd; i--){
                        string[i] = string[i - (lengthReplaceWords - lengthWords)];
                    }
                    string[lengthStringUpdate] = '\0';
                    for(uint8_t i = 0; i < lengthReplaceWords; i++)
                        string[i + locationStart] = replaceWords[i];                
                }
                else{
                    for(uint8_t i = 0; i < lengthReplaceWords; i++)
                        string[i + locationStart] = replaceWords[i];                      
                }
            }
        } 
    }       
}

int main(int argc, char const *argv[])
{
    char string[] = "to learn around the world learn how to do anything. today we learn ab that";
    //capitalWords(string);
    //findWords(string,"learn");
    //replaceString(string,"learn","haha");
    //replaceString(string,"ab","about"); 
    //printf("%s",string);
    return 0;
}
