class Floor_Maker{
public:
int floor[20];
Floor_Maker();
void print();
};

Floor_Maker::Floor_Maker(){

	for(int i=0;i<5;i++)floor[i]=1;
	
	for(int j=5;j<20;j++){

			if(floor[j-1]==0){
			floor[j]=1;
			continue; 
			} 

		floor[j]= rand()%2 ;
		

		}
	};
	
void Floor_Maker::print(){
	std::cout<<"Floor outlay:"<<std::endl;
	for(int i=0;i<20;i++){
		if(floor[i])std::cout<<"1";
		else std::cout<<"0";
		}
	std::cout<<std::endl;
	
	};
	
	
