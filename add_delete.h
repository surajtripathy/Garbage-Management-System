namespace add_delete
{
using namespace std;
void del()
{
fstream fi;
int i;
cout<<"If you want to clear out all login details press 1 \nIf you want to clear out all vehicle details press 2\nIf you want to clear all details of garbage collection press 3"<<endl;
cin>>i;
if(i==1)
{
fi.open("login.csv",ios::out | ios::trunc);
fi.close();
cout<<"All data removed!"<<endl;
}
else if(i==2)
{
fi.open("vehicle.csv",ios::out | ios::trunc);
fi.close();
cout<<"All data removed!"<<endl;
}
else if(i==3)
{
fi.open("dumb.csv",ios::out | ios::trunc);
fi.close();
cout<<"All data removed!"<<endl;
}
}
}
