using namespace std;
namespace supervisor
{
	string username;
	string password;
	string entryuser()
	{
	cout<<"Enter your username"<<endl;
	getline(cin,username);
	return username;
	}
	string entrypass()
	{
	cout<<"Enter your password"<<endl;
	getline(cin,password);
	return password;
	}
}
