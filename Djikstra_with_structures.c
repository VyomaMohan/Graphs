#include<stdio.h>

#define NOE 14
#define NOV 9

#define INF 1000

struct edge{
	int v1;
	int v2;
	int wt;
};
typedef struct edge EDGE;

int adj_mat[NOV][NOV];

//edges with nodes stored in the form of numbers
EDGE edge_list[NOE]={{1,6,1},{2,3,2},{0,2,3},{1,4,3},{5,6,4},{0,3,5},{4,8,5},{7,8,6},{3,6,6},{2,5,9},{0,1,9},{6,8,10},{5,7,12},{6,4,15}};
//EDGE edge_list[NOE]={{0,3,1},{0,2,5},{0,1,3},{0,4,4},{2,1,10},{2,3,2},{1,3,4},{1,4,9},{3,4,7},{3,4,8}};

struct vert{
	int v;
	int visit;
	int cost;
	int parent;
};
typedef struct vert VERT;

VERT vert_list[NOV];

void displayadjmat(){
	int i,j,nzc=0;
	printf("Adjacency matrix:\n");
	for(i=0;i<NOV;i++){
		for(j=0;j<NOV;j++){
			if(adj_mat[i][j]!=0)
			nzc++;
			printf("%2d ",adj_mat[i][j]);
		}
		printf("\n");
	}
	//printf("\n%d",nzc);
}

void djikstra(){
	int key=0;
	
	int i,min,comp_cost,count;
	
	for(i=0;i<NOV;i++){
		vert_list[i].v=i;
		vert_list[i].visit=0;
		vert_list[i].cost=INF;
		vert_list[i].parent=-1;
	}
	
	//vert_list[key].visit=1;
	vert_list[key].cost=0;
	
	while(1){
		min=find_min_vert();
		if(min==INF)
		break;
		vert_list[min].visit=1;
		
		for(i=0;i<NOV;i++){
			if(adj_mat[min][i]!=0){
				comp_cost=vert_list[min].cost+adj_mat[min][i];
				if(comp_cost<vert_list[i].cost){
					vert_list[i].cost=comp_cost;
					vert_list[i].parent=min;
				}
			}
		}
		
		count=0;
		for(i=0;i<NOV;i++){
			if(vert_list[i].visit==1){
				count++;
			}
		}
		if(count==NOV)
		break;
		
	}
}

int find_min_vert(){
	int i,min=INF,key;
	
	for(i=0;i<NOV;i++){
		if(vert_list[i].cost<min&&vert_list[i].visit==0){
			min=vert_list[i].cost;
			key=i;
		}
	}
	
	return key;
}

void displaydjik(){
	int i;
	
	printf("\nNode\tCost\tParent");
	for(i=0;i<NOV;i++){
		printf("\n%2c\t%2d\t%2c",vert_list[i].v+65,vert_list[i].cost,vert_list[i].parent+65);
	}
}


main(){
	int i;
	
	for(i=0;i<NOE;i++){
		adj_mat[edge_list[i].v1][edge_list[i].v2]=edge_list[i].wt;
		adj_mat[edge_list[i].v2][edge_list[i].v1]=edge_list[i].wt;
		
	}
	
	//displayadjmat();
	
	djikstra();
	displaydjik();
}
