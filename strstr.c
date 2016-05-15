const char* StrStr(const char *str1, const char *str2)  
07.{  
08.      assert(NULL != str1 && NULL != str2);  
09.        
10.       
11.      while(*str1 != '\0')  
12.      {  
13.          const char *p = str1;  
14.          const char *q = str2;  
15.          const char *res = NULL;  
16.          if(*p == *q)  
17.          {  
18.                res = p;  
19.                while(*p && *q && *p++ == *q++)  
20.                ;  
21.                  
22.                if(*q == '\0')  
23.                      return res;                      
24.          }  
25.          str1++;  
26.      }  
27.      return NULL;  
28.}  
