#include <stdio.h>

int main ()
    {
        int i=0 , catfood=0 , numrate=0 ,tempc=0,tempj=0,j=0;            
        int ratej[1000] , ratec[1000] ,rate[1000]  , max=0 ;
        double javabeans=0 ,x ,y ;
         
        while (1)
        {
            for (i=1 ; i<=numrate ; i++)    /*�����ʼ��*/
                ratec[i]=0 ;
                ratej[i]=0 ;
            
        
        scanf ("%d%d",&catfood,&numrate);/*����catfood���Ͳֿ���*/
            
        if (catfood == -1 && numrate == -1)
                return 0;                            
            for (i=1;i<=numrate;i++)
            {                                            
                scanf ("%d%d",&ratej[i],&ratec[i]);        /*����ÿ���ֿ�һ�ֵ*/
            }
            javabeans=0;
            for (i=1 ; i<=numrate ;i++)
                {        
                    if (ratec[i]==0)  /*���ֿ������ڶһ������catfoodΪ0����i++*/
                        {                            
                        continue;
                        }
                    for (j=i+1 ; j<=numrate ; j++)
                    {
                        if(ratec[j] == 0){
                            tempc=ratec[i];
                        tempj=ratej[i];
                        ratec[i]=ratec[j];
                        ratej[i]=ratej[j];
                        ratec[j]=tempc;
                        ratej[j]=tempj;
                        break;
                        }
                        x=1.0*ratej[i]/ratec[i];
                        y=1.0*ratej[j]/ratec[j];
                    
                    if (y>=x)    /*�����Լ۱�����*/
                    {
                        tempc=ratec[i];
                        tempj=ratej[i];
                        ratec[i]=ratec[j];
                        ratej[i]=ratej[j];
                        ratec[j]=tempc;
                        ratej[j]=tempj;
                    }

                    }
                }
        
            for (i=1;i<=numrate;i++)
            {     /*��catfood��ȥ���ڶһ���catfood����javabeans���϶һ�����javabeans*/
                if (catfood>=ratec[i])
                    {
                    catfood=catfood-ratec[i];
                    javabeans=javabeans+ratej[i];
                    }
                else 
                {                /*����������ʣ�µ�catfoodС�ڶһ������catfood����������*/
                    javabeans=javabeans+(1.0*catfood*ratej[i]/ratec[i]);
                    break ;
                }
            }
            printf("%.3lf\n",javabeans);
            i=0 ;            /*���ֳ�ʼ��*/
            catfood=0 ;
            numrate=0 ;tempc=0;
            tempj=0;
            j=0;
            
        }
        
      } 