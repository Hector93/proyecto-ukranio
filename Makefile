servidor: Respuesta InterfaceRpc FuncionesUsuario PaqueteDatagrama SocketDatagrama
	g++ servidor.cpp Respuesta.o InterfaceRpc.o FuncionesUsuario.o PaqueteDatagrama.o SocketDatagrama.o -o servidor -g -Wall
generadorVotos: Respuesta InterfaceRpc FuncionesUsuario PaqueteDatagrama SocketDatagrama Solicitud
	g++ generadorVotos.cpp Respuesta.o InterfaceRpc.o FuncionesUsuario.o PaqueteDatagrama.o SocketDatagrama.o Solicitud.o -o generador -g -Wall
Respuesta: SocketDatagrama.o
	g++ Respuesta.cpp -c -g -Wall
InterfaceRpc: FuncionesUsuario.o
	g++ InterfaceRpc.cpp -c -g -Wall
FuncionesUsuario:
	g++ FuncionesUsuario.cpp -c -g -Wall
PaqueteDatagrama:
	g++ PaqueteDatagrama.cpp -c -g -Wall
SocketDatagrama:
	g++ SocketDatagrama.cpp -c -g -Wall
Solicitud: SocketDatagrama.o
	g++ Solicitud.cpp -c -g -Wall