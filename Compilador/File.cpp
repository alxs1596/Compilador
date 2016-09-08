#include "stdafx.h"
#include "File.h"

File::File()
{
	
}

File::~File()
{
}

void File::abrir(std::string nombrearchivo  )
{
	std::string linea;
	std::ifstream nombre;
	nombre.open(nombrearchivo);
	while (!nombre.eof())
	{
		getline(nombre, linea);
		std::cout << linea << std::endl;
	}

}

