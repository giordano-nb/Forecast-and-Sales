#pragma once

#ifndef CLASSE_USUARIO_H
#define CLASSE_USUARIO_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <string>
#include<tchar.h>
#include <locale.h>
using namespace std;

class Usuario
{
	int classe;
	string id, senha, empresa;

	/*
	classes:

	0 - Coders;
	1 - Usu�rio mestre;
	2 - Administradores / Engenheiros;
	3 - Stakeholders.

	Nome:
	Nome de usu�rio utilizado para acesso ao sistema.

	Senha:
	Senha do usu�rio, utilizada para acesso ao sistema.

	Empresa:
	Empresa ao qual o usu�rio est� vinculado.
	*/

public:

	int Adicionar_remover_usuario();

	 int classe_out()
	{
		return classe;
	}
	 string id_out()
	{
		return id;
	}
	 string empresa_out()
	{
		return empresa;
	}


	 void id_in(string id_)
	{
		id = id_;
	}

	 void empresa_in( string empresa_)
	{
		empresa = empresa_;
	}

	 void senha_in( string senha_)
	{
		senha = senha_;
	}


};

int Usuario::Adicionar_remover_usuario()
{
	int i, in;
	int c = 0, s = 1, tent_senha = 0, ent = 0, desconectar = 0, l = 0, enc = 0, x = 0;
	string senha_usada;
	string excluir, pesq;
	Usuario usuario;
	char arquivo[50];
	string arq = empresa + ".txt";
	strcpy_s(arquivo, arq.c_str());

	setlocale(LC_ALL, "Portuguese");

	while (ent == 0)
	{
		//if ((classe == 1) || (classe == 0))    //Apenas usu�rios da classe mestre (1) ou coder(0) podem adicionar/remover usu�rios
		//{
			cout << "A a��o de adicionar / remover um usuario foi selecionada" << endl;
			cout << "Digite 1 caso deseje Adicionar um usu�rio, 2 caso deseje remover e 3 para sair deste menu" << endl;
			cin >> i;

			if (i == 1)    //Adicionar
			{
				cout << "A op��o para adicionar um usu�rio foi selecionada" << endl;

				cout << "Insira sua senha para confirmar a a��o." << endl;
				cin >> senha_usada;

				pesq = "Empresa: " + empresa + "  - Id: " + id + "  - Senha: " + senha_usada;
				char pesquisa[200];
				strcpy_s(pesquisa, pesq.c_str());

				fstream fs;



				fs.open((arquivo), fstream::in);
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
							cout << "A senha informada difere da senha do usu�rio conectado" << endl;
							cout << "Insira a senha correta para prosseguir com a a��o." << endl;
							cin >> senha_usada;
							pesq = "Empresa: " + empresa + "  - Id: " + id + "  - Senha: " + senha_usada;
						}
					}
				}
				fs.close();

				if (tent_senha == 3)
				{
					cout << "A a��o ser� cancelada e o usu�rio desconectado" << endl;
					s = 2;
					ent = 1;
					desconectar = 1;
				}
				if (s == 0)
				{
					usuario.empresa = empresa;
					cout << "Insira agora o id do usu�rio." << endl;
					cin >> usuario.id;
					while (c != 1)
					{
						cout << "Insira o n�vel de acesso do usu�rio" << endl;
						cout << "1 - Caso o novo usu�rio seja um Usu�rio Mestre" << endl;
						cout << "2 - Caso o novo usu�rio seja um Administrador / Engenheiro" << endl;
						cout << "3 - Caso o novo usu�rio seja um Stakeholder" << endl;
						cin >> usuario.classe;
						if ((usuario.classe >= 1) && (usuario.classe <= 3))
						{
							c = 1;
						}
					}
					cout << "Insira uma senha de 8 d�gitos" << endl;
					cin >> usuario.senha;
					while ((usuario.senha).size() != 8)
					{
						cout << "A senha informada n�o possui 8 d�gitos." << endl;
						cout << "Insira uma senha de 8 d�gitos" << endl;
						cin >> usuario.senha;
					}
					fstream fs;
					fs.open((arquivo), fstream::app);
					fs << "Empresa: " << usuario.empresa << "  - Id: " << usuario.id << " - Senha: " << usuario.senha << " - Classe: " << usuario.classe << endl;
					fs.close();
					// IMPORTANTE: Implementar salvamente dos dados em um arquivo
				}
			}
			else if (i == 2)   //Remover
			{
				cout << "A op��o para remover um usu�rio foi selecionada digite 1 para prosseguir." << endl;
				cout << "Ou pressione qualquer outra tecla para retornar ao menu anterior." << endl;
				cin >> in;
				if (in == 1)
				{
					cout << "Insira sua senha para confirmar a a��o." << endl;
					cin >> senha_usada;
					pesq = "Empresa: " + empresa + "  - Id: " + id + "  - Senha: " + senha_usada;
					char pesquisa[500];
					strcpy_s(pesquisa, pesq.c_str());
					fstream fs;
					fs.open((arquivo), fstream::in);
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
								cout << "A senha informada difere da senha do usu�rio conectado" << endl;
								cout << "Insira a senha correta para prosseguir com a a��o." << endl;
								cin >> senha_usada;
								pesq = "Empresa: " + empresa + "  - Id: " + id + "  - Senha: " + senha_usada;
							}
						}
					}
					fs.close();

					if (tent_senha == 3)
					{
						cout << "A a��o ser� cancelada e o usu�rio desconectado" << endl;
						s = 2;
						ent = 1;
						desconectar = 1;
					}
					if (s == 0)
					{
						while (enc == 0)
						{
							cout << "Insira agora o id do usu�rio." << endl;
							cin >> usuario.id;
							excluir = "Empresa: " + usuario.empresa + "  - Id: " + usuario.id;
							char delete_[500];
							strcpy_s(delete_, excluir.c_str());
							fstream fs;
							fs.open((arquivo), fstream::in);
							vector<string> buffer;
							string buff;
							while (x == 1)
							{
								l++;
								getline(fs, buff);
								char buff_[500];
								strcpy_s(buff_, buff.c_str());

								if (strstr(buff_, delete_) != 0)
								{
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
										cout << "O nome procurado n�o foi encontrada, insira-o novamente." << endl;
									}
								}


							}
							fs.close();
							fs.open((arquivo), fstream::out);
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
					ent = 1;
					desconectar = 1;
				}
				else
				{
					cout << "O valor inserido � inv�lido." << endl;
				}
			}
	//	}
	//	else
	//	{
	//		ent = 1;
		//	desconectar = 0;
	//	}
	return desconectar;
}






#endif  /*CLASSE_USUARIO_H*/
