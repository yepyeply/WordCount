#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char *argv[])
{
    
    /*
        printf("main�����յ���%d������\n",argc);//��һ������Ĭ���ǿ�ִ���ļ������ڶ���������ʼ�ǽ��ܵ��Ĳ���
       int i;
       for( i = 0; i < argc; i++ ){
           printf("%s ",argv[i]);    
       }
       printf("\n");
   */
 
    if( argc == 3 ){
            
        //��ӡ���ܵ��Ĳ���
        /*
            int i;
            printf("�յ����ⲿ������");
            for( i = 1; i < argc; i++ ){
                printf("%s ",argv[i]);    
           }
            printf("\n");
       */
       
        //���Զ�ȡ�ļ�������
        char data;
        FILE *fp = fopen(argv[2],"r");
        
        if(!fp){
            printf("�����ļ���ȡʧ��\n");
            return -1;
        }        
        
        //�Բ��������ж�
        
       
        if( !strcmp(argv[1],"-c") ){//�ַ���
            char temp;
            int num = 0;
            temp = fgetc(fp);
            while( temp != EOF ){
                //putchar(temp);
                temp = fgetc(fp);
                num++;
            }
            printf("���ı��ļ����ַ���Ϊ��%d\n",num);
            
        }
        else if( !strcmp(argv[1],"-w") ){//������
            int w = 0;
            char a = fgetc(fp);
            while( a != EOF){
                if( (a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9') ){
                    while( (a >='a' && a <='z') || ( a >='A' && a <='Z') || ( a >='0' && a <='9') )
                       a =fgetc(fp);
                   w++;
                    a =fgetc(fp);
                    
                }
                else
                     a =fgetc(fp);
           }
            printf("���ı��ļ��ĵ�����Ϊ��%d\n",w);
            
        }
        else if( !strcmp(argv[1],"-l") ){//����
            char temp;
            int num = 1;
            temp = fgetc(fp);
            while( temp != EOF ){
                
                //putchar(temp);
                if(temp == '\n'){//�ַ���Ҫ�õ�������ס
                   num++;
               }
               temp = fgetc(fp);
               
               
            }
            printf("���ı��ļ�������Ϊ��%d\n",num);
    
        }
        else{
            printf("���󣺲���������Χ��\n");
            printf("���������-c��-w��-l\n");
        }
        int n=fclose(fp);
    }
    else{
        printf("�������в�������Ҫ3��\n");
        printf("�÷���wc.exe [parameter] [file_name]\n");
    }
    system("pause");
    return 0;
}
