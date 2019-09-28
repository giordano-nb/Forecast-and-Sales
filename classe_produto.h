#pragma once

#ifndef CLASSE_PRODUTO_H
#define CLASSE_PRODUTO_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include<tchar.h>
#include <locale.h>
#include "classe_usuario.h"


using namespace std;


class Produto
{

	int dt, estoque;
	int valor;
	vector<int> demanda;
	string id_p, empresa;

	//	fs << "Empresa: " << produto.empresa << "  - Id: " << produto.id_p << " - Estoque: " << produto.estoque << " - valor: " << produto.valor<< endl;
	//  fs << "Sazionalidade: "<< dt << " - Histórico de Vendas: " << demanda << endl;

	/*
	dt:
	0 - diário;
	1 - semanal;
	2 - quinzenal
	3 - mensal;
	4 - bimestral;
	5 - semestral.
	6 - anual

	Nome:
	Nome de usuário utilizado para acesso ao sistema.

	Senha:
	Senha do usuário, utilizada para acesso ao sistema.

	Empresa:
	Empresa ao qual o usuário está vinculado.
	*/

public:
	int Adicionar_remover_produto(Usuario);
};

int Produto::Adicionar_remover_produto(Usuario usuario)
{
	int i, n, q, rs, estoqu, in, value;
	int num = 10;
	int c = 0, s = 1, tent_senha = 0, ent = 0, desconectar = 0, a = 0, l = 0, K = 0, enc = 0, x = 0;
	string senha_usada, pesq, pesq2, excluir;
	Produto produto;
	char arquivo[50];
	string arq = usuario.empresa_out() + "_arquivo.txt";
	strcpy_s(arquivo, arq.c_str());
	char arquivo2[50];
	arq = usuario.empresa_out() + ".txt";
	strcpy_s(arquivo2, arq.c_str());
	

	setlocale(LC_ALL, "Portuguese");

	while (ent == 0)
	{
		if ((usuario.classe_out() == 1) || (usuario.classe_out() == 0) || (usuario.classe_out() == 2))   //Apenas usuários da classe Administradores/Engenheiros (2), mestre (1) ou coder(0) podem adicionar/remover dados
		{
			cout << "A ação de adicionar / remover dados foi selecionada" << endl;
			cout << "Digite 1 caso deseje Adicionar dados de um produto, 2 caso deseje remover e 3 para sair deste menu" << endl;
			cin >> i;

			if (i == 1)    //Adicionar
			{
				cout << "A opção para adicionar dados foi selecionada" << endl;
				cout << "Insira sua senha para confirmar a ação." << endl;
				cin >> senha_usada;
				pesq = "Empresa: " + usuario.empresa_out() + "  - Id: " + usuario.id_out() + "  - Senha: " + senha_usada;

				char pesquisa[500];
				strcpy_s(pesquisa, pesq.c_str());
				fstream fs;
				fs.open((arquivo2), fstream::in);
				string buff;

				while ((tent_senha != 3) && (enc == 0))
				{//
					getline(fs, buff);
					char buff_[500];
					strcpy_s(buff_, buff.c_str());
					if (strstr(buff_, pesquisa) != 0)
					{//
						enc++;
						cout << "A senha foi confirmada." << endl;
						s = 0;
					}//
					if (buff.size() == 1)
					{//
						tent_senha++;
						if (enc == 0)
						{//
							cout << "A senha informada difere da senha do usuário conectado" << endl;
							cout << "Insira a senha correta para prosseguir com a ação." << endl;
							cin >> senha_usada;
							pesq = "Empresa: " + usuario.empresa_out() + "  - Id: " + usuario.id_out() + "  - Senha: " + senha_usada;
							char pesquisa[500];
							strcpy_s(pesquisa, pesqc_str());
						}//
					}//
				}//

				fs.close();

				if (tent_senha == 3)
				{//
					cout << "A ação será cancelada e o usuário desconectado" << endl;
					s = 2;
					ent = 1;
					desconectar = 1;
				}//
				if (s == 0)   // Adicionar produto - senha confirmada
				{
					produto.empresa = empresa;
					cout << "Insira agora o id do produto." << endl;
					cin >> produto.id_p;
					pesq = "Empresa: " + produto.empresa + "  - Id: " + produto.id_p;

					char pesquisa[500];
					strcpy_s(pesquisa, pesq.c_str());
					fstream fs;
					fs.open((arquivo), fstream::in);
					string buff;
					enc = 0;
					int l_e;

					while (x == 1)
					{//
						l++;
						getline(fs, buff);
						char buff_[500];
						strcpy_s(buff_, buff.c_str());
						if (strstr(buff_, pesquisa) != 0)   // Produto já cadastrado
						{//
							enc++;
							l_e = l;
						}//
						if (buff.size() == 1)
						{//
							x = 0;
						}//
					}//
					fs.close();
					if (enc != 0)
					{
						cout << "O produto selecionado já existe." << endl;
						while (a == 0)
						{
							cout << "Selecione se deseja adicionar dados de estoque ou para previsão de demanda." << endl;
							cout << "Caso deseje inserir dados referentes ao estoque digite 1, caso contrário, digite 2." << endl;
							cin >> q;
							if (q == 1)
							{
								cout << "Insira 1 se for adicionar produtos ao estoque e 2 se for remover" << endl;
								cin >> rs;
								if (rs == 1)
								{
									cout << "Insira a quantidade de produtos adicionados ao estoque." << endl;
									cin >> estoqu;
									pesq = "Empresa: " + produto.empresa + "  - Id: " + produto.id_p + "  - Estoque: ";
									char pesquisa[500];
									strcpy_s(pesquisa, pesq.c_str());
									fstream fs;
									fs.open((arquivo), fstream::in);
									string buff;
									char buffer_e[10] = { a, a, a, a, a, a, a, a, a, a };
									char buffer_v[10] = { a, a, a, a, a, a, a, a, a, a };
									vector <string> buffer_t;
									while (x == 1)
									{
										l++;
										getline(fs, buff);
										char buff_[500];
										strcpy_s(buff_, buff.c_str());
										if (strstr(buff_, pesquisa) != 0)
										{
											while (!isdigit(buffer_e[num]))
											{

												buff.copy(buffer_e, pesq.size(), num);
												num--;
											}
											while (!isdigit(buffer_v[1]))
											{
												num = 0;
												buff.copy(buffer_v, (pesq.size() + 8 + num), 10);
												num++;
											}
											produto.valor = atoi(buffer_v);
											produto.estoque = atoi(buffer_e);
											produto.estoque += estoqu;
											char est[20], val[20];
											_itoa_s(produto.estoque, est, 10);
											_itoa_s(produto.valor, val, 10);
											string est_, val_, buffer__, buffer2__, buffer3__, buffer4__;
											est_ = est;
											val_ = val;
											buffer__ = "Empresa: " + produto.empresa;
											buffer2__ = "  - Id: " + produto.id_p;
											buffer3__ = " - Estoque: " + est_;
											buffer4__ = " - Valor: " + val_;
											buffer__ = ((buffer__ + buffer2__) + buffer3__) + buffer4__;
											buffer_t.push_back(buffer__);

										}
										else
										{
											buffer_t.push_back(buff);
										}
										if (buff.size() == 1)
										{
											x = 0;
										}
										fs.close();

										fs.open((arquivo), fstream::out);

										while (l != 0)
										{
											fs << buffer_t.front() << endl;
											l--;
											buffer_t.erase(buffer_t.begin());
										}
										fs.close();

										a = 1;

									}
								}
								else if (rs == 2)
								{
									cout << "Insira a quantidade de produtos adicionados ao estoque." << endl;
									cin >> estoqu;
									pesq = "Empresa: " + produto.empresa + "  - Id: " + produto.id_p + "  - Estoque: ";
									char pesquisa[500];
									strcpy_s(pesquisa, pesq.c_str());
									fstream fs;
									fs.open((arquivo), fstream::in);
									string buff;
									char buffer_e[10] = { a, a, a, a, a, a, a, a, a, a };
									char buffer_v[10] = { a, a, a, a, a, a, a, a, a, a };
									vector <string> buffer_t;
									while (x == 1)
									{
										l++;
										getline(fs, buff);
										char buff_[500];
										strcpy_s(buff_, buff.c_str());
										if (strstr(buff_, pesquisa) != 0)
										{
											while (!isdigit(buffer_e[num]))
											{
												buff.copy(buffer_e, num, pesq.size());
												num--;
											}
											while (!isdigit(buffer_v[1]))
											{
												num = 0;
												buff.copy(buffer_v, 10, (pesq.size() + 8 + num));
												num++;
											}
											produto.valor = atof(buffer_v);
											produto.estoque = atoi(buffer_e);
											produto.estoque -= estoqu;
											char est[20], val[20];
											_itoa_s(produto.estoque, est, 10);
											_itoa_s(produto.valor, val, 10);
											string est_, val_, buffer__, buffer2__, buffer3__, buffer4__;
											est_ = est;
											val_ = val;
											buffer__ = "Empresa: " + produto.empresa;
											buffer2__ = "  - Id: " + produto.id_p;
											buffer3__ = " - Estoque: " + est_;
											buffer4__ = " - Valor: " + val_;
											buffer__ = ((buffer__ + buffer2__) + buffer3__) + buffer4__;
											buffer_t.push_back(buffer__);

										}
										else
										{
											buffer_t.push_back(buff);
										}
										if (buff.size() == 1)
										{
											x = 0;
										}
										fs.close();

										fs.open((arquivo), fstream::out);

										while (l != 0)
										{
											fs << buffer_t.front() << endl;
											l--;
											buffer_t.erase(buffer_t.begin());
										}
										fs.close();

										a = 1;

									}
								}
								else
								{
									cout << "O valor inserido é inválido" << endl;
									a = 0;
								}
							}
							else if (q == 2)
							{
								a = 1;
								cout << "Indique a quantidade de produtos a serem inseridos." << endl;
								cin >> n;
								vector<int> insert;
								int ins;
								for (int j = 0; j = n; j++)
								{
									cout << "Insira o dado de número " << j << " dos " << n << " a serem adicionados." << endl;
									cin >> ins;
									insert.push_back(ins);

								}
								// Ler dados já existentes no arquivo
								pesq = "Empresa: " + produto.empresa + "  - Id: " + produto.id_p;
								char pesquisa[500];
								strcpy_s(pesquisa, pesq.c_str());
								pesq2 = "Sazionalidade: ";
								fstream fs;
								fs.open((arquivo), fstream::in);
								string buff;
								string buffer_d = "a";
								string buffer_dt = "a";
								vector <string> buffer_t;
								while (x == 1)
								{
									l++;
									getline(fs, buff);
									char buff_[500];
									strcpy_s(buff_, buff.c_str());

									if (K == 1)
									{
										pesq = "- Histórico de Vendas : ";
										char pesquisa[500];
										strcpy_s(pesquisa, pesq.c_str());
										pesq2 = "Sazionalidade: ";

									}
									if ((strstr(buff_, pesquisa) != 0) && (K == 1))
									{

										while (!isdigit(buffer_d[1]))
										{
											num = 0;
											buffer_d = "0";
											buffer_d = buff.substr(pesq.size(), 500);
											num++;
										}
										while (!isdigit(buffer_dt[num]))
										{
											num = 5;
											buffer_dt = "0";
											char buff_[500];
											strcpy_s(buff_, buff.c_str());
											copy(buff_, buff_ + sizeof(buff_), buffer_dt.begin());
											num--;
										}
									}
									else
									{
										buffer_t.push_back(buff);
										if ((strstr(buff_, pesquisa) != 0))
										{
											K++;
										}
									}
									if (buff.size() == 1)
									{
										x = 0;
									}
								}
								// Fill DataNumbers
								vector<int> v;

								for (size_t i = 0; i < buffer_d.size(); ++i)
								{
									// This converts the char into an int and pushes it into vec
									v.push_back(buffer_d[i] - '0');  // The digits will be in the same order as before
								}

								(produto.demanda).assign(v.begin(), v.end());
								(produto.demanda).insert((produto.demanda).begin(), insert.begin(), insert.end());

								char d_t[20], dem[20];
								string dema;
								vector<int> dem__;
								_itoa_s(produto.dt, d_t, 10);
								for (int i = 0; produto.demanda.size() < i; i++)
								{
									dem__.push_back(produto.demanda.back());
									produto.demanda.pop_back();
									sprintf_s(dem, "%d ", dem__[i]);
									dema = dema + dem;
								}
								string dt_, dem_, buffer__, buffer2__;

								dt_ = d_t;
								dem_ = dema;
								buffer__ = "Sazionalidade: " + dt_;
								buffer2__ = "  - Demanda: " + dem_;
								buffer__ = (buffer__ + buffer2__);
								buffer_t.push_back(buffer__);

								fs.close();

								fs.open((arquivo), fstream::out);

								while (l != 0)
								{
									fs << buffer_t.front() << endl;
									l--;
									buffer_t.erase(buffer_t.begin());
								}
								fs.close();
								a = 1;
								cout << "Os dados inseridos foram salvos" << endl;
							}
							else
							{
								cout << "O valor inserido é inválido" << endl;
								a = 0;
							}
						}
					}
					else   // Produto ainda não existe
					{

						produto.empresa = usuario.empresa_out();
						cout << "Insira o id do novo produto a ser cadastrado." << endl;
						cin >> produto.id_p;

						while (c != 1)
						{

							cout << "Insira o período de obtenção dos dados." << endl;

							cout << "0 -  caso os dados sejam diários" << endl;
							cout << "1 -  caso os dados sejam semanais" << endl;
							cout << "2 -  caso os dados sejam quinzenais" << endl;
							cout << "3 -  caso os dados sejam mensais" << endl;
							cout << "4 -  caso os dados sejam bimestrais" << endl;
							cout << "5 -  caso os dados sejam semestrais" << endl;
							cout << "6 -  caso os dados sejam anuais" << endl;
							cin >> produto.dt;

							if ((produto.dt >= 0) && (produto.dt <= 6))
							{
								c = 1;
							}
						}

						cout << "Insira todos osdados necessários para a caracterização do estoque e necessários para previsão de demanda." << endl;
						cout << "Insira a quantidade de produtos adicionados ao estoque." << endl;
						cin >> estoqu;

						while (!(isdigit(estoqu)))
						{
							cout << "O valor inserido é inválido, insira-o novamente." << endl;
							cin >> estoqu;
						}
						produto.estoque = estoqu;
						cout << "Insira o valor do produto, por unidade, presente no estoque." << endl;
						cin >> value;
						while (!(isdigit(value)))
						{
							cout << "O valor inserido é inválido, insira-o novamente." << endl;
							cin >> value;
						}
						produto.valor = value;
						cout << "Indique a quantidade de produtos a serem inseridos." << endl;
						cin >> n;
						vector<int> insert;
						int ins;
						for (int j = 0; j = n; j++)
						{
							cout << "Insira o dado de número " << j << " dos " << n << " a serem adicionados." << endl;
							cin >> ins;
							insert.push_back(ins);

							(produto.demanda).push_back(insert.back());
							insert.pop_back();
						}
						fstream fs;
						fs.open((arquivo), fstream::app);
						fs << "Empresa: " << produto.empresa << "  - Id: " << produto.id_p << " - Estoque: " << produto.estoque << " - valor: " << produto.valor << endl;
						fs << "Sazionalidade: " << produto.dt << " - Histórico de Vendas: ";
						for (int i = 0; produto.demanda.size() < i; i++)
						{
							produto.demanda.pop_back();
							fs << produto.demanda.front();

						}
						fs << endl;
					}
				}
			}
			else if (i == 2)   //Remover
			{

				cout << "A opção para remover um produto foi selecionada digite 1 para prosseguir." << endl;
				cout << "Ou pressione qualquer outra tecla para retornar ao menu anterior." << endl;
				cin >> in;
				if (in == 1)  // IMPORTANTE: Implementar Exclusão dos dados de um usuário em um arquivo
				{
					cout << "Insira sua senha para confirmar a ação." << endl;
					cin >> senha_usada;
					pesq = "Empresa: " + usuario.empresa_out() + "  - Id: " + usuario.id_out() + "  - Senha: " + senha_usada;
					char pesquisa[500];
					strcpy_s(pesquisa, pesq.c_str());

					fstream fs;
					fs.open((arquivo2), fstream::in);
					string buff;

					while ((tent_senha != 3) && (enc == 0))
					{
						getline(fs, buff);
						char buff_[500];
						strcpy_s(buff_, buff.c_str());
						if (strstr(buff_, pesquisa) != 0)
						{
							enc++;
							cout << "A senha foi confirmada." << endl;
							s = 0;
						}
						if (buff.size() == 1)
						{
							tent_senha++;
							if (enc == 0)
							{
								cout << "A senha informada difere da senha do usuário conectado" << endl;
								cout << "Insira a senha correta para prosseguir com a ação." << endl;
								cin >> senha_usada;
								pesq = "Empresa: " + usuario.empresa_out() + "  - Id: " + usuario.id_out() + "  - Senha: " + senha_usada;
							}
						}
					}
					fs.close();

					if (tent_senha == 3)
					{
						cout << "A ação será cancelada e o usuário desconectado" << endl;
						s = 2;
						ent = 1;
						desconectar = 1;
					}
					if (s == 0)
					{
						enc = 0;
						while (enc == 0)
						{
							cout << "Deseja realizar a operação? 0 para prosseguir ou 1 para sair" << endl;
							cin >> x;
							while (!(isdigit(x)))
							{
								cout << "O valor inserido é inválido, insira-o novamente." << endl;
								cin >> x;
							}
							cout << "Insira agora o id do produto." << endl;
							cin >> produto.id_p;
							excluir = "Empresa: " + produto.empresa + "  - Id: " + produto.id_p;
							char delete_[500];
							strcpy_s(delete_, excluir.c_str());
							
							fstream fs;
							fs.open((arquivo), fstream::in);
							vector<string> buffer;
							string buff;
							K = 0;
							while (x == 1)
							{
								l++;
								getline(fs, buff);
								char buff_[500];
								strcpy_s(buff_, buff.c_str());
								if ((strstr(buff_, delete_) != 0) || (K == 1))
								{
									K++;
									buffer.push_back("\0");
									enc++;
								}
								else
								{
									buffer.push_back(buff);
								}
								if (buff.size() == 1)
								{
									x = 0;
									if (enc == 0)
									{
										cout << "O nome procurado não foi encontrada, insira-o novamente." << endl;
									}
								}
							}
							fs.close();
							fs.open((arquivo2), fstream::out);
							while (l != 0)
							{
								fs << buffer.front() << endl;
								l--;
								buffer.erase(buffer.begin());
							}
							fs.close();
						}
					}
				}
			}
			else if (i == 3)   //Sair
			{
				ent == 1;
				desconectar = 1;
			}
			else
			{
				cout << "O valor inserido é inválido." << endl;
			}
		}
		else
		{
			ent == 1;
		}
	}
	return desconectar;
}

#endif


