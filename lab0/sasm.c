#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *trim(char *str)
{
  char *end;

  // Trim leading space
  while(isspace((unsigned char)*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace((unsigned char)*end)) end--;

  // Write new null terminator character
  end[1] = '\0';

  return str;
}

// HashMap<String,Integer> map
// map.get("WRITE") --> 10

// "WRITE" ---> index ---> opcode[index] ---> 10

//char* ops[12] = {"READ","WRITE","LOAD","STORE","ADD","","",""...};
//int opcode[12] = {10,...}

int main(int argc, char* argv[]){
	FILE* f = fopen(argv[1],"r");
	
	//int a[]
	//int* b  
	
	char* st[100]; // String st[] = new String[100];
	char* labels[100];
	int addr[100];
	
	int n=0;
	int k=0;
	while(42){
	  st[n] = (char*) malloc(32);// st[n] = new String("      ...         ")  	
	  char* res = fgets(st[n],32,f); // hello world\n\0
	  if (res==NULL) break;
	  //printf("%s",st[n]);
	  
	  char* p = strchr(st[n],':');
	  
	  
	  if (p!=NULL) {
	    p[0]='\0';
	    labels[k] = trim(st[n]);
	    addr[k]=n;
	    st[n] = trim(p+1);
	    printf("%s|%s\n",labels[k], st[n]);
	    k++;
	  }
	  else{
	    st[n] = trim(st[n]);
	    printf("%s\n",st[n]);
	  }
	  
	  n++;
	}
	fclose(f);
	
	printf("----------------------------\n");
	for(int i=0;i<n;i++){
	  printf("%s\n",st[i]);
	}
	printf("----------------------------\n");	
	for(int i=0;i<k;i++){
	  printf("%s %02d\n",labels[i],addr[i]);
	}
}

