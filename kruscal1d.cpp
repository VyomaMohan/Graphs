#include<stdio.h>
#include<stdlib.h>

#define NOE 14
#define NOV 9

struct edge{
	int v1;
	int v2;
	int wt;
};
typedef struct edge EDGE;

EDGE edge_list[NOE]={{1,6,1},{2,3,2},{0,2,3},{1,4,3},{5,6,4},{0,3,5},{4,8,5},{7,8,6},{3,6,6},{2,5,9},{0,1,9},{6,8,10},{5,7,12},{6,4,15}};
//EDGE edge_list[NOE]={{0,1,1},{0,2,1},{1,3,1},{0,3,2},{2,3,3},{1,2,4}};

main(){
	int arr[NOV];
	int itr,ind,temp1,temp2,vert1,vert2,cost=0;
	
	for(itr=0;itr<NOV;itr++)
		arr[itr]=itr;
		
	printf("\nEdges that are accepted or rejected for Kruscal's algorithm:");
		
	for(itr=0;itr<NOE;itr++){
		vert1=edge_list[itr].v1;
		vert2=edge_list[itr].v2;
		temp1=arr[vert1];
		temp2=arr[vert2];
		if(arr[vert1]!=arr[vert2]){
			printf("\n%c - %c",vert1+65,vert2+65);
			cost=cost+edge_list[itr].wt;
			for(ind=0;ind<NOV;ind++){
				if(arr[ind]==temp1||arr[ind]==temp2){
					arr[ind]=temp1;
				}
			}
		}
		else{
			printf("\nLoop occurs for %c - %c",vert1+65,vert2+65);
		}
	}
	printf("\nMinimum cost is : %d",cost);
}
