#include "network.h"
//Tendo que arreglar
//que count se mande aumentado, y que las maquinas empiezan en 1 no 0

network::network() {
	cout << "starting network object \n";

}

void network::wait_for_message(char *data, int *size) {
	cout << "blocking program , waiting for message ... \n";
}

void network::send_message(char *data, char *address, char *port) {
	cout << "sending " << data << " to " << address << " : " << port << '\n';

}



bool iniciar(vector <string> &direcciones, string mi_ip) {
	cout << "inciando \n";
	package_data data;
	data.actual = 0;
	preguntar_secuencia(&data.animation, data.seq, direcciones);
	data.cnt_maq = direcciones.size();


	if (mi_ip == direcciones[data.seq[0]]) { // empiezo yo!//hot fix	
											 cout << "soy la maquina inicial, y empiezo yo la animacion \n";
		mostrar_secuencia(data.animation);
		data.actual++;
	}

	// pasamos a la siguiente
	{//Trucazo para que client se suicide

		client my_client;
		my_client.startConnection(direcciones[data.seq[data.actual]].c_str());//HOTFIX
		if (!my_client.success()) {
			cout << "could not connect, fatal error \n";
			return 0;
		}
		string msg = compose_msg(data);

		my_client.send_message(msg.c_str(), msg.size());

	}
	if (mi_ip == direcciones[data.seq[0]]) {
		return 1; // exito!	
	}
	// esperamos que nos respondan
	{
		char ans[512]; int sz;
		cout << "Empezamos a escuchar, nos quedamos esperando a recibir un mensaje \n";
		//cout << "escuchando" << '\n';
		server my_server;
		my_server.start_to_listen();
		my_server.wait_for_message(ans, &sz);
		string str_ans;
		complete_string(str_ans, ans, sz);
		decompose_msg(str_ans, data);

		/// debemos mostrar la animacion, y despues responder el mensaje
		mostrar_secuencia(data.animation);
		client my_client;
		data.actual++;
		if (data.actual == data.cnt_maq) data.actual = 0;
		if (data.actual != 0) {
			my_client.startConnection(direcciones[data.seq[data.actual]].c_str());
			string msg = compose_msg(data);

			my_client.send_message(msg.c_str(), msg.size());
		}

	}

	return 1;
}
bool escuchar(vector <string> &direcciones) {
	cout << "escuchando \n";	/// escuchamos y respondemos
	server my_server;
	my_server.start_to_listen();
	char ans[512]; int sz;
	//cout << "esperamos el mensaje . . . \n";
	my_server.wait_for_message(ans, &sz);
	string str_ans;
	complete_string(str_ans, ans, sz);
	package_data data;
	data.cnt_maq = direcciones.size();
	decompose_msg(str_ans, data);	/// mostramos la animacion correspondiente
	mostrar_secuencia(data.animation);	/// respondemos
	data.actual++;
	if (data.actual == data.cnt_maq) return 1; // no need to respond message

	client my_client;
	my_client.startConnection(direcciones[data.seq[data.actual]].c_str());//hotfix
	if (!my_client.success()) {
		cout << "could not connect, fatal error \n";
		return 0;
	}
	string msg = compose_msg(data);
	my_client.send_message(msg.c_str(), msg.size());
	return 1;
}

