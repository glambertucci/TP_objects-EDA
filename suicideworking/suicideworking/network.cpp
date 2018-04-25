#include "network.h"


bool iniciar(vector <string> &direcciones, string mi_ip) {
	package_data data;
	data.actual = 0;
	preguntar_secuencia(&data.animation, data.seq, direcciones);
	data.cnt_maq = direcciones.size();

	if (mi_ip == direcciones[data.seq[0]]) { // inicio	=> Dibujo e incremento actual
		mostrar_secuencia(data.animation);
		data.actual++;
	}
	client my_client;
	my_client.startConnection(direcciones[data.seq[data.actual]].c_str());//mando
	if (!my_client.success()) {
		cout << "could not connect, fatal error \n";
		return 0;
	}
	string msg = compose_msg(data);
	my_client.send_message(msg.c_str(), msg.size());
	return 1;
}

bool escuchar(vector <string> &direcciones) {
	static int count=0;
	static int max_maq=2;//Hot fix
	if (count == max_maq) { count = 0;max_maq = 2; return 1; } //Se que es feo :/
	cout << "escuchando \n";	
	server my_server;
	my_server.start_to_listen();
	char ans[1+255+1]; int sz;
	string str_ans = my_server.wait_for_message();
	package_data data;
	data.cnt_maq = direcciones.size();
	decompose_msg(str_ans, data);	 //Recibe y desarma mensaje
	mostrar_secuencia(data.animation);	// Secuencia
	data.actual++;
	if (data.actual == data.cnt_maq) return 1; //Soy el ultimo no le mando a nadie
	client my_client;
	my_client.startConnection(direcciones[data.seq[data.actual]].c_str());// Mando
	count = data.actual;
	max_maq = data.cnt_maq;
	string msg = compose_msg(data);
	my_client.send_message(msg.c_str(), msg.size());
	return 0;//No soy el ultimo!
}

