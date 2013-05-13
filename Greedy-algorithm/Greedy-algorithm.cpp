#include <stdio.h>

int main ()
    {
        int i=0 , catfood=0 , numrate=0 ,tempc=0,tempj=0,j=0;            
        int ratej[1000] , ratec[1000] ,rate[1000]  , max=0 ;
        double javabeans=0 ,x ,y ;
         
        while (1)
        {
            for (i=1 ; i<=numrate ; i++)    /*数组初始化*/
                ratec[i]=0 ;
                ratej[i]=0 ;
            
        
        scanf ("%d%d",&catfood,&numrate);/*输入catfood数和仓库数*/
            
        if (catfood == -1 && numrate == -1)
                return 0;                            
            for (i=1;i<=numrate;i++)
            {                                            
                scanf ("%d%d",&ratej[i],&ratec[i]);        /*输入每个仓库兑换值*/
            }
            javabeans=0;
            for (i=1 ; i<=numrate ;i++)
                {        
                    if (ratec[i]==0)  /*若仓库里用于兑换所需的catfood为0，则i++*/
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
                    
                    if (y>=x)    /*根据性价比排序*/
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
            {     /*用catfood减去用于兑换的catfood再用javabeans加上兑换到的javabeans*/
                if (catfood>=ratec[i])
                    {
                    catfood=catfood-ratec[i];
                    javabeans=javabeans+ratej[i];
                    }
                else 
                {                /*如果换到最后剩下的catfood小于兑换所需的catfood则这样计算*/
                    javabeans=javabeans+(1.0*catfood*ratej[i]/ratec[i]);
                    break ;
                }
            }
            printf("%.3lf\n",javabeans);
            i=0 ;            /*各种初始化*/
            catfood=0 ;
            numrate=0 ;tempc=0;
            tempj=0;
            j=0;
            
        }
        
      } 