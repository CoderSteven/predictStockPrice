//Shengming Liang
//sl1317	167008982
//project
//ANN

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

const double e = 2.7182818;
const int In = 10;
const int Out = 1;

double sigma(double, double, double, double);
double f(double);//Activation function f(x)
double fd(double);//Derivative of f(x)


double predict(double data[In], double w[Out][In], double v[In][In])
{
	double y[Out];
	double A[In] = { 0 };
	for (int j = 0; j < In; j++)
	{
		for (int k = 0; k < In; k++)
		{
			A[j] = data[k] * v[j][k] + A[j];
		}
	}
	double h[In];
	for (int j = 0; j < In; j++)
	{
		h[j] = f(A[j]);
	}
	double Ah[Out] = { 0 };
	for (int i = 0; i < Out; i++)
	{
		for (int j = 0; j < In; j++)
		{
			Ah[i] = h[j] * w[i][j] + Ah[i];
		}
	}
	for (int i = 0; i < Out; i++)
	{
		y[i] = f(Ah[i]);
	}
	return y[0];
}

double max(double data[])
{
	double max;
	max = data[0];
	for (int i = 1; i < 200; i++)
	{
		if (data[i] > max)
			max = data[i];
	}
	return max;
}


int main()
{
	double eta;//learning rate******** ¦Ç
	double err;//target error********* ¦Å
	double v[In][In];//weights from inputs to hidden layers***Vjk
	double w[Out][In];//weights from hidden layers to output***Wij
	double h1, h2;//hidden layers
	double y[Out];//output
	double data[10][In + 1];//datasets of input and target output
	string readdata1[2540];
	string readdata2[2540];
	string readdata3[2540];
	string readdata4[2540];
	string readdata5[2540];
	string readdata6[2540];
	string readdata7[2540];
	string readdata8[2540];
	string readdata9[2540];
	string readdata10[2540];
	
	double readprice1[200];
	
	double readprice2[200];
	double readprice3[200];
	double readprice4[200];
	double readprice5[200];
	double readprice6[200];
	double readprice7[200];
	double readprice8[200];
	double readprice9[200];
	double readprice10[200];
	
	string dat1[6];
	string dat2[6];
	string dat3[6];
	string dat4[6];
	string dat5[6];
	string dat6[6];
	string dat7[6];
	string dat8[6];
	string dat9[6];
	string dat10[6];

	int order;//i th dataset
	int count_2 = 0;

	double sum;//batch error
	
	
	/*cout << "1.CSCO\n"
		<< "2.FB\n"
		<< "3.GOOG\n"
		<< "4.INTC";
		*/
	int t;
	menu:
	int choice;
	cin >> choice;
	int r = 0;
	double m;
	ifstream file1("cisco_system_historical.csv");
	ofstream filet1("cisco.txt");
	ifstream filep1("cisco.txt");
	ifstream date1("cisco_system_historical.csv");

	ifstream file2("facebook_historical.csv");
	ofstream filet2("facebook.txt");
	ifstream filep2("facebook.txt");
	ifstream date2("facebook_historical.csv");

	ifstream file3("google_historical.csv");
	ofstream filet3("google.txt");
	ifstream filep3("google.txt");
	ifstream date3("google_historical.csv");

	ifstream file4("intel_historical.csv");
	ofstream filet4("intel.txt");
	ifstream filep4("intel.txt");
	ifstream date4("intel_historical.csv");

	ifstream file5("micron_historical.csv");
	ofstream filet5("micron.txt");
	ifstream filep5("micron.txt");
	ifstream date5("micron_historical.csv");

	ifstream file6("microsoft_historical.csv");
	ofstream filet6("microsoft.txt");
	ifstream filep6("microsoft.txt");
	ifstream date6("microsoft_historical.csv");

	ifstream file7("nvdia_historical.csv");
	ofstream filet7("nvdia.txt");
	ifstream filep7("nvdia.txt");
	ifstream date7("nvdia_historical.csv");

	ifstream file8("oracle_historical.csv");
	ofstream filet8("oracle.txt");
	ifstream filep8("oracle.txt");
	ifstream date8("oracle_historical.csv");

	ifstream file9("twitter_historical.csv");
	ofstream filet9("twitter.txt");
	ifstream filep9("twitter.txt");
	ifstream date9("twitter_historical.csv");

	ifstream file10("yahoo_historical.csv");
	ofstream filet10("yahoo.txt");
	ifstream filep10("yahoo.txt");
	ifstream date10("yahoo_historical.csv");

	switch (choice)
	{
	case 1:
		for (int q = 0; q < 2540; q++)
			file1 >> readdata1[q];
		for (int q = 5; q < 2540; q = q + 10)
		{
			filet1 << readdata1[q] << endl;
		}
		for (int q = 0; q < 254; q++)
			filep1 >> readprice1[q];
		for (int q = 0; q < 6; q++)
			date1 >> dat1[q];

		m = max(readprice1);
		for (int k = 0; k < 10; k++)
		{
			for (int l = 0; l < In + 1; l++)
			{
				data[k][l] = readprice1[140 - r] / 2 / m;
				r++;
			}
		}
		break;
		
	case 2:
		for (int q = 0; q < 2000; q++)
			file2 >> readdata2[q];
		for (int q = 5; q < 2000; q = q + 10)
		{
			filet2 << readdata2[q] << endl;
		}
		for (int q = 0; q < 200; q++)
			filep2 >> readprice2[q];		
		for (int q = 0; q < 6; q++)
			date2 >> dat2[q];

		m = max(readprice2);
		for (int k = 0; k < 10; k++)
		{
			for (int l = 0; l < In + 1; l++)
			{
				data[k][l] = readprice2[140 - r] / 2 / m;
				r++;
			}
		}
		break;
	case 3:		
		for (int q = 0; q < 2000; q++)
			file3 >> readdata3[q];		
		for (int q = 5; q < 2000; q = q + 10)
		{
			filet3 << readdata3[q] << endl;
		}		
		for (int q = 0; q < 200; q++)
			filep3 >> readprice3[q];		
		for (int q = 0; q < 6; q++)
			date3 >> dat3[q];

		m = max(readprice3);
		for (int k = 0; k < 10; k++)
		{
			for (int l = 0; l < In + 1; l++)
			{
				data[k][l] = readprice3[140 - r] / 2 / m;
				r++;
			}
		}
		break;
		
	case 4:		
		for (int q = 0; q < 2000; q++)
			file4 >> readdata4[q];		
		for (int q = 5; q < 2000; q = q + 10)
		{
			filet4 << readdata4[q] << endl;
		}		
		for (int q = 0; q < 200; q++)
			filep4 >> readprice4[q];		
		for (int q = 0; q < 6; q++)
			date4 >> dat4[q];
		m = max(readprice4);
		for (int k = 0; k < 10; k++)
		{
			for (int l = 0; l < In + 1; l++)
			{
				data[k][l] = readprice4[140 - r] / 2 / m;
				r++;
			}
		}
		break;
	case 5:
		
		for (int q = 0; q < 2000; q++)
			file5 >> readdata5[q];
		
		for (int q = 5; q < 2000; q = q + 10)
		{
			filet5 << readdata5[q] << endl;
		}
		
		for (int q = 0; q < 200; q++)
			filep5 >> readprice5[q];
		
		for (int q = 0; q < 6; q++)
			date5 >> dat5[q];
		m = max(readprice5);
		for (int k = 0; k < 10; k++)
		{
			for (int l = 0; l < In + 1; l++)
			{
				data[k][l] = readprice5[140 - r] / 2 / m;
				r++;
			}
		}
		break;
	case 6:
		
		for (int q = 0; q < 2000; q++)
			file6 >> readdata6[q];
		
		for (int q = 5; q < 2000; q = q + 10)
		{
			filet6 << readdata6[q] << endl;
		}
		
		for (int q = 0; q < 200; q++)
			filep6 >> readprice6[q];
		
		for (int q = 0; q < 6; q++)
			date6 >> dat6[q];
		m = max(readprice6);
		for (int k = 0; k < 10; k++)
		{
			for (int l = 0; l < In + 1; l++)
			{
				data[k][l] = readprice6[140 - r] / 2 / m;
				r++;
			}
		}
		break;
	case 7:
		for (int q = 0; q < 2000; q++)
			file7 >> readdata7[q];
		for (int q = 5; q < 2000; q = q + 10)
		{
			filet7 << readdata7[q] << endl;
		}
		for (int q = 0; q < 200; q++)
			filep7 >> readprice7[q];
		for (int q = 0; q < 6; q++)
			date7 >> dat7[q];
		m = max(readprice7);
		for (int k = 0; k < 10; k++)
		{
			for (int l = 0; l < In + 1; l++)
			{
				data[k][l] = readprice7[140 - r] / 2 / m;
				r++;
			}
		}
		break;
	case 8:
		
		for (int q = 0; q < 2000; q++)
			file8 >> readdata8[q];
		
		for (int q = 5; q < 2000; q = q + 10)
		{
			filet8 << readdata8[q] << endl;
		}
		for (int q = 0; q < 200; q++)
			filep8 >> readprice8[q];
		for (int q = 0; q < 6; q++)
			date8 >> dat8[q];
		m = max(readprice8);
		for (int k = 0; k < 10; k++)
		{
			for (int l = 0; l < In + 1; l++)
			{
				data[k][l] = readprice8[140 - r] / 2 / m;
				r++;
			}
		}
		break;
	case 9:
		for (int q = 0; q < 2000; q++)
			file9 >> readdata9[q];
		for (int q = 5; q < 2000; q = q + 10)
		{
			filet9 << readdata9[q] << endl;
		}
		for (int q = 0; q < 200; q++)
			filep9 >> readprice9[q];
		for (int q = 0; q < 6; q++)
			date9 >> dat9[q];
		m = max(readprice9);
		for (int k = 0; k < 10; k++)
		{
			for (int l = 0; l < In + 1; l++)
			{
				data[k][l] = readprice9[140 - r] / 2 / m;
				r++;
			}
		}
		break;
	case 10:
		for (int q = 0; q < 2000; q++)
			file10 >> readdata10[q];
		for (int q = 5; q < 2000; q = q + 10)
		{
			filet10 << readdata10[q] << endl;
		}
		for (int q = 0; q < 200; q++)
			filep10 >> readprice10[q];

		for (int q = 0; q < 6; q++)
			date10 >> dat10[q];
		m = max(readprice10);
		for (int k = 0; k < 10; k++)
		{
			for (int l = 0; l < In + 1; l++)
			{
				data[k][l] = readprice10[140 - r] / 2 / m;
				r++;
			}
		}
		break;
		
	}

	srand(time(0) + rand());
	//Initialize weights with random number between -1 and 1
	for (int j = 0; j < In; j++) {
		for (int k = 0; k < In; k++) {
			v[j][k] = ((double)rand()) / RAND_MAX;// *2 - 1;//modify this comment to get (-1,1)
		}
	}

	for (int i = 0; i < Out; i++)
	{
		for (int j = 0; j < In; j++)
		{
			w[i][j] = ((double)rand()) / RAND_MAX;// *2 - 1;//modify this comment to get (-1,1)
		}
	}

	eta = 0.01;
	cout << "Please input the target error: ";
	cin >> err;

	while (1)
	{
		double delV[In][In] = { 0 };//change weights from x to h***¡÷Vjk
		double delW[Out][In] = { 0 };//change weights from h to y***¡÷Wij
		order = 0;
		sum = 0;
		while (order < 10)
		{
			//double A1 = sigma(v[0][0], v[0][1], data[order][0], data[order][1]);//weigted sum of inputs of hidden unit 1
			//double A2 = sigma(v[1][0], v[1][1], data[order][0], data[order][1]);//weigted sum of inputs of hidden unit 2
			double A[In] = { 0 };
			for (int j = 0; j < In; j++)
			{
				for (int k = 0; k < In; k++)
				{
					A[j] = data[order][k] * v[j][k] + A[j];
				}
			}
			double h[In];
			for (int j = 0; j < In; j++)
			{
				h[j] = f(A[j]);
			}
			//h1 = f(A1);
			//h2 = f(A2);
			//double A3 = sigma(w[0][0], w[0][1], h1, h2);//weigted sum of inputs of output
			double Ah[Out] = { 0 };
			for (int i = 0; i < Out; i++)
			{
				for (int j = 0; j < In; j++)
				{
					Ah[i] = h[j] * w[i][j] + Ah[i];
				}
			}
			for (int i = 0; i < Out; i++)
			{
				y[i] = f(Ah[i]);
			}

			//¡÷Wij=¦Ç*(y|target-y|actual)*f'(A3)*hj
			for (int i = 0; i < 1; i++)
			{
				for (int j = 0; j < In; j++)
				{
					delW[i][j] = eta*(data[order][In] - y[i])*fd(Ah[i])*h[j] + delW[i][j];
				}
			}
			//delW[0][0] = eta*(data[order][2] - y)*fd(Ah)*h1 + delW[0][0];
			//delW[0][1] = eta*(data[order][2] - y)*fd(Ah)*h2 + delW[0][1];

			//¡÷Vjk=¦Ç*(y|target-y|actual)*f'(A3)*Wij*f'(A1,2)*x
			for (int j = 0; j < In; j++)
			{
				for (int k = 0; k < In; k++)
				{
					for (int i = 0; i < Out; i++)
					{
						delV[j][k] = eta*(data[order][In] - y[i])*fd(Ah[i])*w[i][j] * fd(A[j])*data[order][k] + delV[j][k];
					}
				}
			}
			//delV[0][0] = eta*(data[order][2] - y)*fd(Ah)*w[0][0] * fd(A1)*data[order][0] + delV[0][0];
			//delV[0][1] = eta*(data[order][2] - y)*fd(Ah)*w[0][0] * fd(A1)*data[order][1] + delV[0][1];
			//delV[1][0] = eta*(data[order][2] - y)*fd(Ah)*w[0][1] * fd(A2)*data[order][0] + delV[1][0];
			//delV[1][1] = eta*(data[order][2] - y)*fd(Ah)*w[0][1] * fd(A2)*data[order][1] + delV[1][1];

			for (int i = 0; i < Out; i++)
			{
				sum = 0.5*pow(data[order][2] - y[i], 2) + sum;
			}
			order++;
		}//end of functuion while(inside)

		if (count_2 == 0)
			cout << "\n2. The first-batch error is: " << sum << endl;

		if (sum < err)
		{
			cout << "\n3. The final weights are"
				<< "\nv11 = " << v[0][0]
				<< "\nv12 = " << v[0][1]
				<< "\nv21 = " << v[1][0]
				<< "\nv22 = " << v[1][1]
				<< "\nw11 = " << w[0][0]
				<< "\nw12 = " << w[0][1] << endl;

			cout << "\n4. The final error is: " << sum << endl;

			cout << "\n5. The total number of batches run through in the training is: " << count_2 + 1 << endl;
			break;
		}//end of function if

		for (int j = 0; j < In; j++)
		{
			for (int k = 0; k < In; k++)
			{
				v[j][k] = v[j][k] + delV[j][k];
			}
		}

		for (int i = 0; i < Out; i++)
		{
			for (int j = 0; j < In; j++)
			{
				w[i][j] = w[i][j] + delW[i][j];
			}
		}

		count_2++;
	}//end of function while(outside)

	//int x1 = 0.2, x2 = 0.4;
	//double p = predict(x1, x2, v[0][0], v[1][0], v[0][1], v[1][1], w[0][0], w[0][1]);
	double da[In];
	int x = 0;
	double p;
	ofstream output("ann.csv", ios::app);
	switch (choice)
	{
	case 1:
		for (int s = 0; s < In; s++)
		{
			da[s] = readprice1[9 - x];
			x++;
		}
		p = predict(da, w, v) * 2 * m;
		cout << "The predict price is " << p << endl;
		output << "CSCO," << "cisco_system," << "Cisco_system Inc.," << dat1[1] <<","<< dat1[5] << ","<<p << endl;
		break;
		
	case 2:
		for (int s = 0; s < In; s++)
		{
			da[s] = readprice2[9 - x];
			x++;
		}
		p = predict(da, w, v) * 2 * m;
		cout << "The predict price is " << p << endl;
		output << "FB," << "facebook," << "Facebook Inc.," << dat2[1] <<","<< dat2[5] <<","<< p << endl;
		break;
	case 3:
		for (int s = 0; s < In; s++)
		{
			da[s] = readprice3[9 - x];
			x++;
		}
		p = predict(da, w, v) * 2 * m;
		cout << "The predict price is " << p << endl;
		output << "GOOG," << "google," << "Google Inc.," << dat3[1] <<","<< dat3[5] <<","<< p << endl;
		break;
	case 4:
		for (int s = 0; s < In; s++)
		{
			da[s] = readprice4[9 - x];
			x++;
		}
		p = predict(da, w, v) * 2 * m;
		cout << "The predict price is " << p << endl;
		output << "INTC," << "intel," << "Intel Corporation," << dat4[1] <<","<< dat4[5] <<","<< p << endl;
		break;
	case 5:
		for (int s = 0; s < In; s++)
		{
			da[s] = readprice5[9 - x];
			x++;
		}
		p = predict(da, w, v) * 2 * m;
		cout << "The predict price is " << p << endl;
		output << "MU," << "micron," << "Micron Technology," << dat5[1] <<","<< dat5[5] <<","<< p << endl;
		break;
	case 6:
		for (int s = 0; s < In; s++)
		{
			da[s] = readprice6[9 - x];
			x++;
		}
		p = predict(da, w, v) * 2 * m;
		cout << "The predict price is " << p << endl;
		output << "MSFT," << "microsoft," << "Microsoft Corporation," << dat6[1] <<","<< dat6[5] <<","<< p << endl;
		break;
	case 7:
		for (int s = 0; s < In; s++)
		{
			da[s] = readprice7[9 - x];
			x++;
		}
		p = predict(da, w, v) * 2 * m;
		cout << "The predict price is " << p << endl;
		output << "NVDA," << "nvdia," << "Nvdia Corporation," << dat7[1] <<","<< dat7[5] <<","<< p << endl;
		break;
	case 8:
		for (int s = 0; s < In; s++)
		{
			da[s] = readprice8[9 - x];
			x++;
		}
		p = predict(da, w, v) * 2 * m;
		cout << "The predict price is " << p << endl;
		output << "ORCL," << "oracle," << "Oracle Corporation," << dat8[1] <<","<< dat8[5] <<","<< p << endl;
		break;
	case 9:
		for (int s = 0; s < In; s++)
		{
			da[s] = readprice9[9 - x];
			x++;
		}
		p = predict(da, w, v) * 2 * m;
		cout << "The predict price is " << p << endl;
		output << "TWTR," << "twitter," << "Twitter Inc.," << dat9[1] <<","<< dat9[5] <<","<< p << endl;
		break;
	case 10:
		for (int s = 0; s < In; s++)
		{
			da[s] = readprice10[9 - x];
			x++;
		}
		p = predict(da, w, v) * 2 * m;
		cout << "The predict price is " << p << endl;
		output << "YHOO," << "yahoo," << "Yahoo Inc.," << dat10[1] <<","<< dat10[5] <<","<< p << endl;
		break;
		

	default:
		break;
	}
	goto menu;
	system("pause");
	return 0;
}//end of main function


double sigma(double a, double b, double c, double d)
{
	return a*c + b*d;
}

double f(double x)
{
	return 1 / (1 + pow(e, -x));
}

double fd(double x)
{
	return pow(e, -x) / pow(pow(e, -x) + 1, 2);
}

