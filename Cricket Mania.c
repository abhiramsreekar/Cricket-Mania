#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct score 
{
    char name[15];
    char status[20];
    int ourscore;
    int compscore;
};
void blue();
void green();
void red();
void purple();
void yellow();
void reset();
void display()
{
        purple();
        printf("\n\t*********************\n");
        printf("\n\t*                                                       *\n");
        printf("\n\t*                WELCOME TO CRICKET MANIA               *\n");
        printf("\n\t*                                                       *\n");
        printf("\n\t*********************\n");
        printf("\n\t------This is a fascinating cricket game simulator-------\n");
        printf("\n\t-------------------------RULES---------------------------\n");
        printf("\n\t#1 You get to enter your name\n");
        printf("\n\t#2 Whoever wins the toss, chooses either to bat or bowl\n");
        printf("\n\t#3 You need to choose one number from 1,2,4 and 6 only\n");
        printf("\n\t#4 If the number you choose and the computer choose are the same\n");
        printf("\n\t!!!!!!!!Then the batsman gets OUT!!!!!!!!\n");
        printf("\n\t#5 If numbers are different then the number you throw gets added to the score\n");
        printf("\n\t#6 After the batsman gets out, the first innings will be done\n");
        printf("\n\t#7 The total score will be set as the target and the opponent will chase that score\n");
        printf("\n\t#8 If the target is achieved, that player will win the GAME\n");
        printf("\n\t*I HOPE YOU ARE CLEAR WITH THE RULES\n");
        reset();
}
int cc()
{
        int num=rand()%4;
        switch(num)
        {
                case 0:{return 1;break;}
                case 1:{return 2;break;}
                case 2:{return 4;break;}
                case 3:{return 6;break;}
        }
}
int toss()
{
        int num=rand()%2;
        return num;
}
int compchoice()
{
        int num=rand()%2;
        return num;
}
int start()
{
        clrscr();
        int ch;
        printf("\n*Lets start with the toss*\n");
        printf("\nEnter 0 for heads (OR) 1 for tails : ");
        scanf("%d",&ch);
        if(ch==0)
                return 0;
        else if(ch==1)
                return 1;
        else
        {
                printf("\nINVALID INPUT!!\n");
                start();
        }
}
int inp()
{
        clrscr();
        int ch;
        printf("\nEnter a number (1/2/4/6) : ");
        scanf("%d",&ch);
        if(ch==1||ch==2||ch==4||ch==6)
                return ch;
        else
        {
                printf("\nINVALID INPUT!!\n");
                inp();
        }
}
int batorbowl()
{
        clrscr();
        int c;
        printf("\nEnter 0 to Bat (OR) 1 to Bowl\n");
        scanf("%d",&c);
        if(c==0)
                return 0;
        else if(c==1)
                return 1;
        else
        {
                printf("\nINVALID INPUT!!!!\n");
                batorbowl();
        }
}
void red() {
  printf("\033[1;31m");
}

void yellow() {
  printf("\033[1;33m");
}
void blue() {
printf("\033[1;34m");
}
void green() {
printf("\033[1;32m");
}
void purple() {
printf("\033[1;35m");
}
void reset() {
  printf("\033[0m");
}
int webatinn1();
int webatinn2(int t);
int compbatinn1();
int compbatinn2(int t);
int main()
{
        struct score s;
        FILE *fp;
        int temp=0,temp2=0,temp3=0,check;
        char choice,target1=0,target2=0;
        display();
        do{
        target1=0,target2=0;
        printf("\nEnter your name : ");
        scanf("%s",s.name);
        clrscr();
        srand(time(0));
        temp=start();
        srand(time(0));
        temp2=toss();
        if(temp==temp2)
        {
                if(temp2==0)
                {
					blue();
				    printf("\nIT IS HEADS!!! So what are you gonna do?\n");
                    reset();
				}
				else if(temp2==1)
                {
					blue();
					printf("\nIT IS TAILS!!! So what are you gonna do?\n");
                    reset();
				}
				choice=batorbowl();
                if(choice==0)
                {
                        printf("\nYou chose to bat, all the very best for that\n");
                        target1=webatinn1();
                }
                else if(choice==1)
                {
                        printf("\nYou chose to bowl, all the very best for that\n");
                        target1=compbatinn1();
                }
                printf("\nCongrats!! The First Innings end now\n");
                if(choice==0)
                {
                        printf("\nYour performance was brilliant all the while\n");
                        printf("\nThe target for computer to chase is %d\n",target1);
                        printf("\n*GOOD LUCK!!!\n");
                        target2=compbatinn2(target1);
                        printf("\nWOW!! That was a thrilling game\n");
                        if(target1>target2)
                        {
                                strcpy(s.status,"Victory");
                                s.ourscore=target1;
                                s.compscore=target2;
                                printf("\n*****SCORE-BOARD****\n");
                                printf("\nName of the Player  : %s\n",s.name);
                                printf("\nStatus of the Match : %s\n",s.status);
                                printf("\nOur Score           : %d\n",s.ourscore);
                                printf("\nComputer's Score    : %d\n",s.compscore);
                                fp=fopen("Stats.txt","w");
                                fprintf(fp,"\n*****SCORE-BOARD****\n");
                                fprintf(fp,"\nName of the Player  : %s\n",s.name);
                                fprintf(fp,"\nStatus of the Match : %s\n",s.status);
                                fprintf(fp,"\nOur Score           : %d\n",s.ourscore);
                                fprintf(fp,"\nComputer's Score    : %d\n",s.compscore);
                                fclose(fp);
                                printf("\nWOHOOOO!!!!!!! YOU WON THE GAME\n");
                                printf("\nYOU BET COMPUTER WITH A DIFFERENCE OF %d, AMAZING SHOWW!!!!\n",target1-target2);
                                printf("\nEnter 0 to Play again (OR) any other number to exit : ");
                                scanf("%d",&check);
                        }
                        else
                        {
                                strcpy(s.status,"Lost");
                                s.ourscore=target1;
                                s.compscore=target2;
                                printf("\n*****SCORE-BOARD****\n");
                                printf("\nName of the Player  : %s\n",s.name);
                                printf("\nStatus of the Match : %s\n",s.status);
                                printf("\nOur Score           : %d\n",s.ourscore);
                                printf("\nComputer's Score    : %d\n",s.compscore);
                                fp=fopen("Stats.txt","w");
                                fprintf(fp,"\n*****SCORE-BOARD****\n");
                                fprintf(fp,"\nName of the Player  : %s\n",s.name);
                                fprintf(fp,"\nStatus of the Match : %s\n",s.status);
                                fprintf(fp,"\nOur Score           : %d\n",s.ourscore);
                                fprintf(fp,"\nComputer's Score    : %d\n",s.compscore);
                                fclose(fp);
                                printf("\nYOUR PERFORMANCE WAS FABULOUS!!!!!!\n");
                                printf("\nBut unfortunately you LOST to computer\n");
                                printf("\nBetter luck next time!!!!\n");
                                printf("\nEnter 0 to Play again (OR) any other number to exit : ");
                                scanf("%d",&check);
                        }
                }
                else if(choice==1)
                {
                        printf("\nYour bowling was AMAZING!!!\n");
                        printf("\nThe target for you to chase is %d\n",target1);
                        printf("\n*GOOD LUCK\n");
                        target2=webatinn2(target1);
                        printf("\nWOW!! That was a fantastic game\n");
                        if(target1>target2)
                        {
                                strcpy(s.status,"Lost");
                                s.ourscore=target2;
                                s.compscore=target1;
                                printf("\n*****SCORE-BOARD****\n");
                                printf("\nName of the Player  : %s\n",s.name);
                                printf("\nStatus of the Match : %s\n",s.status);
                                printf("\nOur Score           : %d\n",s.ourscore);
                                printf("\nComputer's Score    : %d\n",s.compscore);
                                fp=fopen("Stats.txt","w");
                                fprintf(fp,"\n*****SCORE-BOARD****\n");
                                fprintf(fp,"\nName of the Player  : %s\n",s.name);
                                fprintf(fp,"\nStatus of the Match : %s\n",s.status);
                                fprintf(fp,"\nOur Score           : %d\n",s.ourscore);
                                fprintf(fp,"\nComputer's Score    : %d\n",s.compscore);
                                fclose(fp);
                                printf("\nYOUR BATTING WAS OUTSTANDING!!!!!!\n");
                                printf("\nBut unfortunately you LOST to computer\n by %d runs",target1-target2);
                                printf("\nBetter luck next time!!!!\n");
                                printf("\nEnter 0 to Play again (OR) any other number to exit : ");
                                scanf("%d",&check);
                                printf("\n");
                        }
                        else
                        {
                                strcpy(s.status,"Victory");
                                s.ourscore=target2;
                                s.compscore=target1;
                                printf("\n*****SCORE-BOARD****\n");
                                printf("\nName of the Player  : %s\n",s.name);
                                printf("\nStatus of the Match : %s\n",s.status);
                                printf("\nOur Score           : %d\n",s.ourscore);
                                printf("\nComputer's Score    : %d\n",s.compscore);
                                fp=fopen("Stats.txt","w");
                                fprintf(fp,"\n*****SCORE-BOARD****\n");
                                fprintf(fp,"\nName of the Player  : %s\n",s.name);
                                fprintf(fp,"\nStatus of the Match : %s\n",s.status);
                                fprintf(fp,"\nOur Score           : %d\n",s.ourscore);
                                fprintf(fp,"\nComputer's Score    : %d\n",s.compscore);
                                fclose(fp);
                                printf("\nWOHOOOO!!!YOU WON THE GAME\n");
                                printf("\nYou BET computer, you stole the show!!!!!\n");
                                printf("\nEnter 0 to Play again (OR) any other number to exit : ");
                                scanf("%d",&check);
                                printf("\n");
                        }
                }
        }
        else
        {
                printf("\nBad luck!! The computer won the toss\n");
                srand(time(0));
                printf("\nThe computer chooses to ");
                srand(time(0));
                temp3=compchoice();
                switch(temp3)
                {
                        case 0:
                        {
                                printf("bat\n");
                                target1=compbatinn1();break;
                        }
                        case 1:
                        {
                                printf("bowl\n");
                                target1=webatinn1();break;
                        }
                }
                printf("\nThat was an incredible 1st innings!!\n");
                if(temp3==1)
                {
                        printf("\nYour performance was brilliant all the while\n");
                        printf("\nThe target for computer to chase is %d\n",target1);
                        printf("\n*GOOD LUCK!!!\n");
                        target2=compbatinn2(target1);
                        printf("\nWOW!! That was a thrilling game\n");
                        if(target1>target2)
                        {
                                strcpy(s.status,"Victory");
                                s.ourscore=target1;
                                s.compscore=target2;
                                printf("\n*****SCORE-BOARD****\n");
                                printf("\nName of the Player  : %s\n",s.name);
                                printf("\nStatus of the Match : %s\n",s.status);
                                printf("\nOur Score           : %d\n",s.ourscore);
                                printf("\nComputer's Score    : %d\n",s.compscore);
                                fp=fopen("Stats.txt","w");
                                fprintf(fp,"\n*****SCORE-BOARD****\n");
                                fprintf(fp,"\nName of the Player  : %s\n",s.name);
                                fprintf(fp,"\nStatus of the Match : %s\n",s.status);
                                fprintf(fp,"\nOur Score           : %d\n",s.ourscore);
                                fprintf(fp,"\nComputer's Score    : %d\n",s.compscore);
                                fclose(fp);
                                printf("\nWOHOOOO!!!!!!! YOU WON THE GAME\n");
                                printf("\nYOU BET computer WITH A DIFFERENCE OF %d, AMAZING SHOWW!!!!\n",target1-target2);
                                printf("\nEnter 0 to Play again (OR) any other number to exit : ");
                                scanf("%d",&check);
                                printf("\n");
                        }
                        else
                        {
                                strcpy(s.status,"Lost");
                                s.ourscore=target1;
                                s.compscore=target2;
                                printf("\n*****SCORE-BOARD****\n");
                                printf("\nName of the Player  : %s\n",s.name);
                                printf("\nStatus of the Match : %s\n",s.status);
                                printf("\nOur Score           : %d\n",s.ourscore);
                                printf("\nComputer's Score    : %d\n",s.compscore);
                                fp=fopen("Stats.txt","w");
                                fprintf(fp,"\n*****SCORE-BOARD****\n");
                                fprintf(fp,"\nName of the Player  : %s\n",s.name);
                                fprintf(fp,"\nStatus of the Match : %s\n",s.status);
                                fprintf(fp,"\nOur Score           : %d\n",s.ourscore);
                                fprintf(fp,"\nComputer's Score    : %d\n",s.compscore);
                                fclose(fp);
                                printf("\nYOUR PERFORMANCE WAS FABULOUS!!!!!!\n");
                                printf("\nBut unfortunately you LOST to computer\n");
                                printf("\nBetter luck next time!!!!\n");
                                printf("\nEnter 0 to Play again (OR) any other number to exit : ");
                                scanf("%d",&check);
                                printf("\n");
                        }
                }
                else if(temp3==0)
                {
                        printf("\nYour bowling was AMAZING!!!\n");
                        printf("\nThe target for you to chase is %d\n",target1);
                        printf("\n*GOOD LUCK\n");
                        target2=webatinn2(target1);
                        printf("\nWOW!! That was a fantastic game\n");
                        if(target1>target2)
                        {
                                strcpy(s.status,"Lost");
                                s.ourscore=target2;
                                s.compscore=target1;
                                printf("\n*****SCORE-BOARD****\n");
                                printf("\nName of the Player  : %s\n",s.name);
                                printf("\nStatus of the Match : %s\n",s.status);
                                printf("\nOur Score           : %d\n",s.ourscore);
                                printf("\nComputer's Score    : %d\n",s.compscore);
                                fp=fopen("Stats.txt","w");
                                fprintf(fp,"\n*****SCORE-BOARD****\n");
                                fprintf(fp,"\nName of the Player  : %s\n",s.name);
                                fprintf(fp,"\nStatus of the Match : %s\n",s.status);
                                fprintf(fp,"\nOur Score           : %d\n",s.ourscore);
                                fprintf(fp,"\nComputer's Score    : %d\n",s.compscore);
                                fclose(fp);
                                printf("\nYOUR BATTING WAS OUTSTANDING!!!!!!\n");
                                printf("\nBut unfortunately you LOST to computer by %d runs\n",target1-target2);
                                printf("\nBetter luck next time!!!!");
                                printf("\nEnter 0 to Play again (OR) any other number to exit : ");
                                scanf("%d",&check);
                                printf("\n");
                        }
                        else
                        {
                                strcpy(s.status,"Victory");
                                s.ourscore=target2;
                                s.compscore=target1;
                                printf("\n*****SCORE-BOARD****\n");
                                printf("\nName of the Player  : %s\n",s.name);
                                printf("\nStatus of the Match : %s\n",s.status);
                                printf("\nOur Score           : %d\n",s.ourscore);
                                printf("\nComputer's Score    : %d\n",s.compscore);
                                fp=fopen("Stats.txt","w");
                                fprintf(fp,"\n*****SCORE-BOARD****\n");
                                fprintf(fp,"\nName of the Player  : %s\n",s.name);
                                fprintf(fp,"\nStatus of the Match : %s\n",s.status);
                                fprintf(fp,"\nOur Score           : %d\n",s.ourscore);
                                fprintf(fp,"\nComputer's Score    : %d\n",s.compscore);
                                fclose(fp);
                                printf("\nWOHOOOO!!!YOU WON THE GAME\n");
                                printf("\nYou BET computer, you stole the show!!!!!");
                                printf("\nEnter 0 to Play again (OR) any other number to exit : ");
                                scanf("%d",&check);
                                printf("\n");
                        }
                }
        }}while(check==0);
        printf("Thank you for playing!!\n");
        return 0;
}
int webatinn1()
{
        clrscr();
        int r,total=0,v,temp=0,fours=0,sixes=0;
        printf("\n-----INNINGS 1-----\n");
        printf("\nYou are batting\n");
        do
        {
                srand(time(0));
                v=cc();
                temp=v;
                r=inp();
                yellow();
				printf("\nYour input = %d \t Computer's input = %d\n",r,temp);
                reset();
                if(r!=temp)
                {
                        switch(r)
                        {
                                case 1:{blue();printf("\nA simple single run!\n");reset();break;}
                                case 2:{blue();printf("\nGood run! 2 runs from that ball\n");reset();break;}
                                case 4:{blue();printf("\nPOWW!!! a wonderful four\n");reset();fours++;break;}
                                case 6:{blue();printf("\nWOAHHH!!! That's a sixerrr\n");reset();sixes++;break;}
                        }
                        total=total+r;
                }
                else
                {
                       red();
					   printf("\n**OUTTT!!!!\n");
                       reset();
					   printf("\n*TARGET=%d*\n",total);
                       break;
                }
                printf("\n->TOTAL=%d",total);
        }while(r!=temp);
        printf("\n*INNINGS 1 ENDS*\n");
        return total;
}
int compbatinn1()
{
        clrscr();
        int r,total=0,v,temp=0;
        printf("\n-----INNINGS 1-----\n");
        printf("\n You are bowling\n");
        do
        {
                srand(time(0));
                v=cc();
                temp=v;
                r=inp();
                yellow();
				printf("\nComputer's input = %d\tYour input = %d \n",temp,r);
                reset();
				if(r!=temp)
                {
                        switch(temp)
                        {
                                case 1:{blue();printf("\nGood ball! Only a single\n");reset();break;}
                                case 2:{blue();printf("\nComputer goes for a two \n");reset();break;}
                                case 4:{blue();printf("\nA fourrr!!! You should be careful with your bowling\n");reset();break;}
                                case 6:{blue();printf("\nThats a massive six by computer!! Check on the fielding\n");reset();break;}
                        }
                        total=total+temp;
                }
                else
                {
                        red();
						printf("\n**OUTTT!!!!\n");
                        reset();
						printf("\n*TARGET=%d*\n",total);
                        break;
                }
                printf("\n->TOTAL=%d",total);
        }while(r!=temp);
 printf("\n*INNINGS 1 ENDS*\n");
        return total;
}
int webatinn2(int t)
{
        clrscr();
        int r,total=0,v,temp=0,fours=0,sixes=0;
        printf("\n-----INNINGS 2-----\n");
        printf("\n You are batting\n");
        do
        {
                srand(time(0));
                v=cc();
                temp=v;
                r=inp();
                yellow();
				printf("\nYour input = %d \t Computer's input = %d\n",r,temp);
                reset();
				if(r!=temp)
                {
                        switch(r)
                        {
                                case 1:{blue();printf("\nA simple single run!\n");reset();break;}
                                case 2:{blue();printf("\nGood run! 2 runs from that ball\n");reset();break;}
                                case 4:{blue();printf("\nPOWW!!! a wonderful four\n");reset();fours++;break;}
                                case 6:{blue();printf("\nWOAHHH!!! That's a sixerrr\n");reset();sixes++;break;}
                        }
                        total=total+r;
                }
                else if(r==temp)
                {
                        red();
						printf("\nOUT!!!\n");
                        reset();
						break;
                }
                else if(total>t)
                        break;
                printf("\n -> TOTAL=%d\n",total);
        }while(total<=t);
        printf("\n*MATCH IS OVER\n");
        return total;
}
int compbatinn2(int t)
{
        clrscr();
        int r,total=0,v,temp=0;
        printf("\n-----INNINGS 2-----\n");
        printf("\n You are bowling\n");
        do
        {
                srand(time(0));
                v=cc();
                temp=v;
                r=inp();
                yellow();
				printf("\nComputer's input = %d\tYour input = %d \n",temp,r);
                reset();
				if(r!=temp)
                {
                        switch(temp)
                        {
                                case 1:{blue();printf("\nGood ball! Only a single\n");reset();break;}
                                case 2:{blue();printf("\nComputer goes for a two \n");reset();break;}
                                case 4:{blue();printf("\nA fourrr!!! You should be careful with your bowling\n");reset();break;}
                                case 6:{blue();printf("\nThats a massive six by computer!! Check on the fielding\n");reset();break;}
                        }
                        total=total+temp;
                }
                else if(r==temp)
                {
                        red();
						printf("\nOUT!!!\n");
                        reset();
						break;
                }
                else if(total>t)
                        break;
                printf("\n -> TOTAL=%d\n",total);
        }while(total<=t);
        printf("\n*MATCH IS OVER\n");
        return total;
}
