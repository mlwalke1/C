using namespace std;
#include <fstream>
#include <iostream>

struct nodeType {
	int key;
	int row;
	int col;
};

class prims 
{
	private:
		nodeType nodes[6];
		int graph[6][6];
		nodeType cuts[20];
		
	public:
		prims();
		void input();
		void output();
		void spanningtree();
};

prims::prims()
{	

}

void prims::input()
{
	ifstream f("input.txt");
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			f >> graph[i] [j];
}

void prims::output() {
	cout << "Input Graph from input.txt: " << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << endl;
		for (int j = 0; j < 6; j++)
			cout << graph[i] [j]  << " ";
	}
	cout << endl;
	nodes[0].key = 600;
	cout << nodes[0].key;
	
}

void prims::spanningtree()
{
	
	nodeType temp;
	
	//get new coords
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			if(graph[i][j] != 0)
			{ 
				temp.key = graph[i][j];
				temp.row = i;
				temp.col = j;
				cuts.push(temp);
			}
		}
		
	}
	//reinitialize graph
	//add points to matrix
}


int main(){
	prims p;
	
	p.input();
	p.output();

	
	return 0;
}