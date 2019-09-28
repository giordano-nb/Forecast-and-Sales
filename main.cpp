#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include<tchar.h>
#include <locale.h>
#include "classe_produto.h"
#include "classe_usuario.h"

using namespace std;

int main()
{
	Usuario usuario;
	Produto produto;
	string pesq_, empresa_, id_, senha_;
	int desconectar = 0, tent_senha = 0, enc = 0, opcao;



	setlocale(LC_ALL, "Portuguese");

	cout << "Bem-Vindo ao Forecast & Sales." << endl;
	cout << "Realize o login para realizar alguma ação no sistema." << endl;
	cout << "Insira a Empresa ao qual está associado." << endl;
	cin >> empresa_;
	usuario.empresa_in(empresa_);
	cout << "Insira o Id do usuário para entrar no sistema." << endl;
	cin >> id_;
	usuario.id_in(id_);
	cout << "Insira sua senha  para entrar no sistema." << endl;
	cin >> senha_;
	usuario.senha_in(senha_);

	pesq_ = "Empresa: " + usuario.empresa_out() + "  - Id: " + usuario.id_out() + "  - Senha: " + senha_;
	char arquivo[50];
	string arq = usuario.empresa_out() + ".txt";
	strcpy_s(arquivo, arq.c_str());
	
	fstream fs;

	char pesquisa[200];
	strcpy_s(pesquisa, pesq_.c_str());
	

	fs.open((arquivo), fstream::in);
	string buff;

	while ((tent_senha != 3) && (enc == 0))
	{
		getline(fs, buff);
		char buff_[500];
		strcpy_s(buff_, buff.c_str());
		char* a = (strstr(buff_, pesquisa));
		if (strstr(buff_, pesquisa) != 0)
		{
			enc++;
			cout << "O usuário realizou o login com sucesso." << endl;
		}
		if (buff.size() == 1)
		{
			tent_senha++;
			if (enc == 0)
			{
				cout << "A senha, empresa ou usuário informados não foram encontrados." << endl;
				cout << "Insira informações previamente cadastradas para prosseguir com o login." << endl;
				cout << "Insira a Empresa ao qual está associado." << endl;
				cin >> empresa_;
				usuario.empresa_in( empresa_);
				cout << "Insira o Id do usuário para entrar no sistema." << endl;
				cin >> id_;
				usuario.id_in( id_);
				cout << "Insira sua senha  para entrar no sistema." << endl;
				cin >> senha_;
				usuario.senha_in( senha_);
				pesq_ = "Empresa: " + usuario.empresa_out() + "  - Id: " + usuario.id_out() + "  - Senha: " + senha_;
				char arquivo[50];
				string arq = usuario.empresa_out() + ".txt";
				strcpy_s(arquivo, arq.c_str());
				}
		}
	}


	while (desconectar==0)
	{

		cout << "Bem-vindo " << usuario.id_out() << " selecione uma das ações abaixo do sistema" << endl;

		cout << "Insira o número correspondente a ação que se deseja realizar." << endl;

		cout << "0 - Inserir/remover usuário;" << endl;
		cout << "1 -  Inserir/remover/modificar produto;" << endl;
		cout << "2 - Compra de produtos" << endl;
		cout << "3 - deslogar " << endl;
		cin >> opcao;

		if (opcao == 0)
		{
			desconectar = usuario.Adicionar_remover_usuario();
		}
		else if (opcao == 1)
		{
			desconectar = produto.Adicionar_remover_produto(usuario);
		}

		else if (opcao == 2) {}

		else if (opcao == 3)
		{
			desconectar = 1;
		}
		else
		{
			cout << "O valor inserido é inválido, por favor repita a operação." << endl;
		}
	}
}

