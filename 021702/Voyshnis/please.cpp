#include "work.h"


int main()
{
	unsigned int start_time = clock();
	int s, t, current, ch,ch1; //s-stroka t-stolbik
	vector <int> added;
	vector <int> deleted;
	setlocale(LC_ALL, "ru");
	
	//TESTА
		ifstream filea("testa.txt");

		if (filea)
		{
			filea >> current;
			filea >> s >> t;
			for (int i = 0;i < 6;i++)
			{
				filea >> ch;
				added.push_back(ch);
			}
			for (int i = 0;i < 5;i++)
			{
				filea >> ch1;
				deleted.push_back(ch1);
			}

		}
		cout << endl << "TEST" << ' '<<current<<s<<t << endl;

		Test(current, s, t, added, deleted);
		cout << "================";
		cout << endl << endl;

		


	//TESTB
		deleted.clear();
		added.clear();
		ifstream fileb("testb.txt");

		if (fileb)
		{
			fileb >> current;
			fileb >> s >> t;
			for (int i = 0;i < 6;i++)
			{
				fileb >> ch;
				added.push_back(ch);
			}
			for (int i = 0;i < 5;i++)
			{
				fileb >> ch1;
				deleted.push_back(ch1);
			}

		}
		cout << endl << "TEST" << ' ' << current << s << t << endl;

		Test(current, s, t, added, deleted);
		cout << "================";
		cout << endl << endl;

		//TESTC
		deleted.clear();
		added.clear();
		ifstream filec("testc.txt");

		if (filec)
		{
			filec >> current;
			filec >> s >> t;
			for (int i = 0;i < 6;i++)
			{
				filec >> ch;
				added.push_back(ch);
			}
			for (int i = 0;i < 5;i++)
			{
				filec >> ch1;
				deleted.push_back(ch1);
			}

		}
		cout << endl << "TEST" << ' ' << current << s << t << endl;

		Test(current, s, t, added, deleted);
		cout << "================";
		cout << endl << endl;

		//TEST D

		deleted.clear();
		added.clear();
		ifstream filed("testd.txt");

		if (filed)
		{
			filed >> current;
			filed >> s >> t;
			for (int i = 0;i < 6;i++)
			{
				filed >> ch;
				added.push_back(ch);
			}
			for (int i = 0;i < 5;i++)
			{
				filed >> ch1;
				deleted.push_back(ch1);
			}

		}
		cout << endl << "TEST" << ' ' << current << s << t << endl;

		Test(current, s, t, added, deleted);
		cout << "================";
		cout << endl << endl;

		//TEST E

		deleted.clear();
		added.clear();
		ifstream filee("teste.txt");

		if (filee)
		{
			filee >> current;
			filee >> s >> t;
			for (int i = 0;i < 6;i++)
			{
				filee >> ch;
				added.push_back(ch);
			}
			for (int i = 0;i < 5;i++)
			{
				filee >> ch1;
				deleted.push_back(ch1);
			}

		}
		cout << endl << "TEST" << ' ' << current << s << t << endl;

		Test(current, s, t, added, deleted);
		cout << "================";
		cout << endl << endl;
		//TESTF
		deleted.clear();
		added.clear();
		ifstream filef("testf.txt");

		if (filef)
		{
			filef >> current;
			filef >> s >> t;
			for (int i = 0;i < 6;i++)
			{
				filef >> ch;
				added.push_back(ch);
			}
			for (int i = 0;i < 5;i++)
			{
				filef >> ch1;
				deleted.push_back(ch1);
			}

		}
		cout << endl << "TEST" << ' ' << current << s << t << endl;

		Test(current, s, t, added, deleted);
		cout << "================";
		cout << endl << endl;
	//TEST G
		deleted.clear();
		added.clear();
		ifstream fileg("testg.txt");

		if (fileg)
		{
			fileg >> current;
			fileg >> s >> t;
			for (int i = 0;i < 6;i++)
			{
				fileg >> ch;
				added.push_back(ch);
			}
			for (int i = 0;i < 5;i++)
			{
				fileg >> ch1;
				deleted.push_back(ch1);
			}

		}
		cout << endl << "TEST" << ' ' << current << s << t << endl;

		Test(current, s, t, added, deleted);
		cout << "================";
		cout << endl << endl;
		//TEST H
		deleted.clear();
		added.clear();
		ifstream fileh("testh.txt");

		if (fileh)
		{
			fileh >> current;
			fileh >> s >> t;
			for (int i = 0;i < 6;i++)
			{
				fileh >> ch;
				added.push_back(ch);
			}
			for (int i = 0;i < 5;i++)
			{
				fileh >> ch1;
				deleted.push_back(ch1);
			}

		}
		cout << endl << "TEST" << ' ' << current << s << t << endl;

		Test(current, s, t, added, deleted);
		cout << "================";
		cout << endl << endl;
		//TEST I
		deleted.clear();
		added.clear();
		ifstream filei("testi.txt");

		if (filei)
		{
			filei >> current;
			filei >> s >> t;
			for (int i = 0;i < 6;i++)
			{
				filei >> ch;
				added.push_back(ch);
			}
			for (int i = 0;i < 5;i++)
			{
				filei >> ch1;
				deleted.push_back(ch1);
			}

		}
		cout << endl << "TEST" << ' ' << current << s << t << endl;

		Test(current, s, t, added, deleted);
		cout << "================";
		cout << endl << endl;
		//TEST J
		deleted.clear();
		added.clear();
		ifstream filej("testj.txt");

		if (filej)
		{
			filej >> current;
			filej >> s >> t;
			for (int i = 0;i < 6;i++)
			{
				filej >> ch;
				added.push_back(ch);
			}
			for (int i = 0;i < 5;i++)
			{
				filej >> ch1;
				deleted.push_back(ch1);
			}

		}
		cout << endl << "TEST" << ' ' << current << s << t << endl;

		Test(current, s, t, added, deleted);
		cout << "================";
		cout << endl << endl;
	
		unsigned int end_time = clock(); 
		unsigned int search_time = end_time - start_time; 
		//TEST K
		cout << "TEST TIME: " << endl;
		cout << endl;
		cout << "TIME: " << search_time/1000.0<<"c"<<endl;
		cout << "================";
		cout << endl << endl;

		cout <<endl<<endl<< "\t T H E E N D"<<endl<<endl;
	return 0;
}