#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    char left_hs[] = "./the1 < ./test-cases/";
    char for_out[] = "./test-cases/";
    char right_hs[] = " >temp_out.txt";
    char control_string[100];
    FILE *fp = NULL;
    FILE *outp = NULL;
    FILE *controlp = NULL;
    int mychar;
    int i = 0;
    int counter = 0;
    fp = fopen("testcases.txt","r");
    while ((mychar = fgetc(fp)) != EOF)
    {
        char temp_buffer[50];
        if (mychar != '\n')
        {
            temp_buffer[i++] = mychar;
        }
        else
        {
            temp_buffer[i] = '\0';
            if (counter % 2 ==0)
            {
                int k = 0;
                for (i = 0; i < 22; i++)
                {
                    control_string[i] = left_hs[i];
                }
                while (temp_buffer[k] != '\0')
                {
                    control_string[i++] = temp_buffer[k++];
                }
                for (k = 0; k < 14; k++,i++)
                {
                    control_string[i] = right_hs[k];
                }
                control_string[i] = '\0';
                counter++;
                system(control_string);
            }
            else
            {
                int k = 0;
                for (i = 0; i < 13; i++)
                {
                    control_string[i] = for_out[i];
                }
                while (temp_buffer[k] != '\0')
                {
                    control_string[i++] = temp_buffer[k++];
                }
                control_string[i] = '\0';
                counter++;
                int c1,c2;
                char line[300];
                int line_counter = 0;
                int false_counter = 0;
                outp = fopen("temp_out.txt","r");
                controlp = fopen(control_string,"r");
                while ((c1 = fgetc(controlp)) != EOF)
                {
                    if (c1 != '\n')
                    {
                        line[k++] = c1;
                    }
                    else
                    {
                        line_counter++;
                        line[k] = '\0';
                        int m = 0;
                        while ((c2 = fgetc(outp)) != '\n')
                        {
                            if (c2 != line[m++])
                            {
                                k = 0;
                                break;
                            }
                        }
                        if (m != k)
                        {
                            false_counter++;
                        }
                        k = 0;
                    }
                }
                if (false_counter == line_counter+1)
                {
                    int i = 0;
                    while (temp_buffer[i] != '\0')
                    {
                        i++;
                    }
                    temp_buffer[i-4] = '\0';
                    printf("test-case: %s FAIL\n",temp_buffer);
                }
                else
                {
                    int i = 0;
                    while (temp_buffer[i] != '\0')
                    {
                        i++;
                    }
                    temp_buffer[i-4] = '\0';
                    printf("test-case: %s PASS\n",temp_buffer);   
                }
                fclose(outp);
                fclose(controlp);
            }
            i=0;
        }
    }
    fclose(fp);
    return 0;
}