#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <math.h>
#include <conio.h>

using namespace std;



double determ_solve(int order, double mat[100][100])
{
	int i,j,v;
	double d;
	int sign;
	double temp = 0;
	double temp2 = 0;
	i = 0;
	j = 0;
	v = 0;
	d = 1;
	sign = 0;
	double ilusion_mat[100][100];
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++)
		{
			ilusion_mat[i][j] = mat[i][j];
		}
	}
	for (i = 0; i < order; i++)
	{
		for (v = i + 1; v < order; v++)
		{
			if (abs(ilusion_mat[i][i])<abs(ilusion_mat[v][i])) 
			{
				sign++;
				for (j = 0; j<order; j++) 
				{
					temp = ilusion_mat[i][j];
					ilusion_mat[i][j] = ilusion_mat[v][j];
					ilusion_mat[v][j] = temp;
				}
			}
		}
			
	}
		

	for (i = 0; i < order - 1; i++)
	{
		for (v = i + 1; v<order; v++)
		{
			if (ilusion_mat[i][i] == 0)
			{
				return 0;
			}
			else
			{
				temp2 = ilusion_mat[v][i] / ilusion_mat[i][i];
				for (j = 0; j<order; j++)
					ilusion_mat[v][j] = ilusion_mat[v][j] - temp2 * ilusion_mat[i][j];
			}
			
		}
	}
		

	for (i = 0; i<order; i++) 
	{
		d = d * ilusion_mat[i][i];
	}
	if (sign % 2 == 0) 
	{
		return d;
	}
	else 
	{
		return -d;
	}
	
}

int main()
{
	double det_var[100][100];
	for (int i = 0; i < 100; i++)
	{
		for (int v = 0; v < 100; v++)
		{
			det_var[v][i] = 0;
		}

	}
	double det[100][100];
	for (int i = 0; i < 100; i++)
	{
		for (int v = 0; v < 100; v++)
		{
			det[v][i] = 0;
		}
	}
	float var_equation[101][102];
	for (int i = 0; i < 102; i++)
	{
		for (int v = 0; v < 101; v++)
		{
			var_equation[v][i] = 0;
		}
	}
	float equation_sum[101];
	for (int i = 0; i<101; i++)
	{
		equation_sum[i] = 0;
	}
	float equation_minuse[101];
	for (int i = 0; i<101; i++)
	{
		equation_minuse[i] = 0;
	}
	float equation_subs[101];
	for (int i = 0; i<101; i++)
	{
		equation_subs[i] = 0;
	}

	int NoOfVar;
	string nameto;
	string substest3;
	string substest4;
	int reqno;
	string substest;
	string substest2;
	char debugg;
	float num;
	int n1;
	int uo = 0;
	int n2;
	int m;
	float zero = 0;
	int var_num;
	int counter = 0;
	int print_no = 0;
	string equal = "=";
	string determine = "";
	string determine2 = "";
	string determine3 = "";
	string determinelast = "";
	string saver = "";
	string equation;
	string eq_num;
	int eq_num_check;
	string eq_help = "equation";
	string eq_help2 = "column";
	string col_num;
	int var_no_name_check = 0;
	int var_naming = 0;
	int var_no_name;
	int col_num_check;
	string name = "";
	string var_name[101];
	string var_name_alphapitic[101];
	int c;
	int n;
	cin >> n;
	float var[101];
	for (int i = 0; i<101; i++)
	{
		var_name[i] = "zzzzzzzzzzz";
	}
	for (int b = 0; b<101; b++)
	{
		var[b] = 0;
	}

	for (int i = 1; i <= n; i++)
	{

		cin >> equation;
		for (int j = 0; j<equation.length(); j++)
		{

			if (isalpha(equation[j]) or equation[j] == '_')
			{
				if (saver == "-")
				{

					saver = "-1";
				}
				else if (saver == "")
				{
					saver = "1";
				}
				for (int u = 1; u <= equation.length(); u++)
				{

					if (equation[j + 1] == '+' or equation[j + 1] == '-' or equation[j + 1] == '=' or j + 1 == equation.length())
					{
						name += equation[j];
						for (int o = 1; o <= 100; o++)
						{
							if (var_name[o] == name)
							{
								var_no_name = o;
								var_num = var_no_name;
								var_no_name_check = 1;
								break;

							}

						}
						if (var_no_name_check == 0)
						{
							var_naming++;
							var_num = var_naming;

						}
						break;



					}
					else
					{
						name += equation[j];

						j++;
					}
				}



				if ((equation.substr(j)).find('=') != std::string::npos)
				{

					num = atof(saver.c_str());
					var[var_num] += num;
					var_name[var_num] = name;
					saver = "";
					name = "";


				}
				else
				{

					num = atof(saver.c_str());
					var[var_num] -= num;
					var_name[var_num] = name;
					saver = "";
					name = "";


				}




			}
			else if (equation[j] == '+')
			{
				var_num = 0;
				num = atof(saver.c_str());
				if ((equation.substr(j)).find('=') != std::string::npos)
				{
					var[var_num] -= num;
				}
				else
				{
					var[var_num] += num;
				}

				saver = "";
			}
			else if (equation[j] == '-')
			{
				var_num = 0;
				num = atof(saver.c_str());
				if ((equation.substr(j)).find('=') != std::string::npos)
				{
					var[var_num] -= num;
				}
				else
				{
					var[var_num] += num;
				}

				saver = "-";
			}

			else if (equation[j] == '=')
			{
				var_num = 0;
				num = atof(saver.c_str());
				var[var_num] -= num;
				saver = "";

			}
			else
			{
				saver = saver + equation[j];

			}
			var_no_name_check = 0;

		}
		for (int p = 1; p <= 100; p++)
		{
			var_equation[p][i] = var[p];


		}

		var_equation[0][i] = var[0] + atof(saver.c_str());
		for (int k = 0; k<101; k++)
		{
			var[k] = 0;
		}
		saver = "";
		var_no_name_check = 0;




	}
	for (int p = 0; p <= 100; p++)
	{
		var_name_alphapitic[p] = var_name[p];
	}

	for (int big = 1; big<101; big++)
	{
		for (int small = big + 1; small<101; small++)
		{

			if (var_name_alphapitic[small]<var_name_alphapitic[big])
			{
				string temp = var_name_alphapitic[big];
				var_name_alphapitic[big] = var_name_alphapitic[small];
				var_name_alphapitic[small] = temp;

			}

		}


	}
	for (int z = 0; z < n; z++)
	{
		for (int v = 1; v <= 100; v++)
		{
			for (int t = 1; t <= 100; t++)
			{
				if (var_name_alphapitic[v] == var_name[t])
				{


					det[z][v - 1] = var_equation[t][z + 1];






				}
			}



		}

	}
	for (int k = 1; k <= 100; k++)
	{
		if (var_name[k] != "zzzzzzzzzzz")
		{
			counter += 1;

		}
	}
	NoOfVar = counter;

	counter = 0;



	while (1)
	{
		string user_input;
		getline(cin, user_input);
		if (user_input == "quit")
		{
			break;
		}
		else if (user_input == "num_vars")
		{

			cout << NoOfVar << "\n";
		}
		else if (eq_help == user_input.substr(0, 8))
		{


			eq_num = user_input.substr(9, 100);
			eq_num_check = atoi(eq_num.c_str());
			if (eq_num_check > n)
			{

			}
			else
			{
				for (int l = 1; l <= 100; l++)
				{
					if (l == eq_num_check)
					{
						for (int v = 1; v <= 100; v++)
						{
							for (int t = 1; t <= 100; t++)
							{
								if (var_name_alphapitic[v] == var_name[t])
								{
									if (var_equation[t][l] == float(0))
									{

									}
									else
									{
										if (var_equation[t][l]>0 and print_no != 0)
										{
											cout << "+";
										}
										cout << var_equation[t][l] << var_name[t];
										print_no++;
									}
								}
							}



						}


					}
				}
				cout << "=" << var_equation[0][eq_num_check] << "\n";
				print_no = 0;

			}

		}
		else if (eq_help2 == user_input.substr(0, 6))
		{

			col_num = user_input.substr(7);
			for (int o = 1; o <= 100; o++)
			{
				if (var_name[o] == col_num)
				{
					col_num_check = o;
					break;
				}
			}




			for (int l = 1; l <= 101; l++)
			{
				if (l == col_num_check)
				{
					for (int z = 1; z <= n; z++)
					{
						cout << var_equation[l][z] << endl;
						col_num_check = 0;
						col_num = "";
					}
				}
			}

		}
		else if ("add" == user_input.substr(0, 3))
		{
			substest = user_input.substr(4);
			substest2 = substest.substr(substest.find(" ") + 1);
			n1 = atoi(user_input.substr(4).c_str());
			n2 = atoi(substest2.c_str());
			for (int zen = 0; zen<101; zen++)
			{
				equation_sum[zen] = var_equation[zen][n1] + var_equation[zen][n2];

			}
			for (int v = 1; v <= 100; v++)
			{
				for (int t = 1; t <= 100; t++)
				{
					if (var_name_alphapitic[v] == var_name[t])
					{
						if (equation_sum[t] == float(0))
						{

						}
						else
						{
							if (equation_sum[t]>0 and print_no != 0)
							{
								cout << "+";
							}
							cout << equation_sum[t] << var_name[t];
							print_no++;
						}
					}
				}



			}




			cout << "=" << equation_sum[0] << "\n";
			print_no = 0;

		}
		else if ("subtract" == user_input.substr(0, 8))
		{
			substest = user_input.substr(9);
			substest2 = substest.substr(substest.find(" ") + 1);
			n1 = atoi(user_input.substr(9).c_str());
			n2 = atoi(substest2.c_str());
			for (int zen = 0; zen<101; zen++)
			{
				equation_minuse[zen] = var_equation[zen][n1] - var_equation[zen][n2];

			}
			for (int v = 1; v <= 100; v++)
			{
				for (int t = 1; t <= 100; t++)
				{
					if (var_name_alphapitic[v] == var_name[t])
					{
						if (equation_minuse[t] == float(0))
						{

						}
						else
						{
							if (equation_minuse[t]>0 and print_no != 0)
							{
								cout << "+";
							}
							cout << equation_minuse[t] << var_name[t];
							print_no++;
						}
					}
				}



			}




			cout << "=" << equation_minuse[0] << "\n";
			print_no = 0;
		}
		else if ("substitute" == user_input.substr(0, 10))

		{
			substest = user_input.substr(11);
			substest2 = substest.substr(substest.find(" "));
			substest3 = substest2.substr(1);
			substest4 = substest3.substr(substest3.find(" ") + 1);

			nameto = substest.substr(0, substest.find(" "));
			n1 = atoi(substest2.substr(1).c_str());

			n2 = atoi(substest4.c_str());
			for (int zen = 0; zen<101; zen++)
			{
				if (nameto == var_name[zen])
				{
					reqno = zen;
					break;
				}
			}
			for (int zen = 1; zen<101; zen++)
			{
				if (zen != reqno)
					equation_subs[zen] = var_equation[zen][n1] - ((var_equation[reqno][n1] / var_equation[reqno][n2])*var_equation[zen][n2]);

			}
			equation_subs[0] = var_equation[0][n1] - ((var_equation[reqno][n1] / var_equation[reqno][n2])*var_equation[0][n2]);

			for (int v = 1; v <= 100; v++)
			{
				for (int t = 1; t <= 100; t++)
				{
					if (var_name_alphapitic[v] == var_name[t])
					{
						if (equation_subs[t] == float(0))
						{

						}
						else
						{
							if (equation_subs[t]>0 and print_no != 0)
							{
								cout << "+";
							}
							cout << equation_subs[t] << var_name[t];
							print_no++;
						}
					}
				}
			}
			cout << "=" << equation_subs[0] << "\n";
			print_no = 0;
		}
		else if ("D" == user_input)
		{
			for (int i = 0; i < n; i++)
			{
				for (int v = 0; v < 100; v++)
				{
					if (det[i][v] == 0)
					{
						for (int t = 0; t < n; t++)
						{
							if (det[t][v] != 0)
							{
								cout << 0 << "\t";
								break;
							}
						}
					}
					else
					{
						cout << det[i][v] << "\t";
					}
				}
				cout << "\n";
			}
		}
		else if ("D " == user_input.substr(0, 2))
		{
			nameto = user_input.substr(user_input.find(" ") + 1);
			for (int z = 1; z <= n; z++)
			{
				for (int v = 1; v <= 100; v++)
				{
					for (int t = 1; t <= 100; t++)
					{
						if (var_name_alphapitic[v] == var_name[t])
						{
							if (var_name[t] == nameto)

							{
								cout << var_equation[0][z] << "\t";
							}
							else if (var_equation[t][z] == float(0))
							{
								for (int i = 1; i <= n; i++)
								{
									if (var_equation[t][i] != 0)
									{
										cout << 0 << "\t";
										break;
									}
								}
							}
							else
							{
								cout << var_equation[t][z] << "\t";
							}
						}
					}
				}
				cout << "\n";
			}
		}
		else if ("D_value" == user_input)
		{
			
			cout << determ_solve(n, det) << "\n";
			
		}
		else if ("solve" == user_input)
		{
			if (NoOfVar != n)
			{
				cout << "No Solution" << "\n";
			}
			else
			{
				for (int i = 1; i <= n; i++)
				{
					for (int z = 0; z < n; z++)
					{
						for (int v = 1; v <= 100; v++)
						{
							for (int t = 1; t <= 100; t++)
							{
								if (var_name_alphapitic[v] == var_name[t])
								{
									if (v == i)
									{
										det_var[z][v - 1] = var_equation[0][z + 1];
									}

									else
									{
										det_var[z][v - 1] = var_equation[t][z + 1];

									}
								}
							}
						}
					}
					if (determ_solve(n, det) == 0)
					{
						cout << "No Solution" << "\n";
						break;
					}
					else
					{
						cout << var_name_alphapitic[i] << '=' << determ_solve(n, det_var) / determ_solve(n, det) << endl;
					}
				}
			}
		}
	}
	return 0;
}