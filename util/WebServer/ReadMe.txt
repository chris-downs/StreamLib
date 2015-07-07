========================================================================
       CONSOLE APPLICATION : WebServer
========================================================================

Este es un servidor de aplicaciones simple con interfaz web.

Indice
-------------------------------
1. Configuraci�n
	1.1 webapp.conf
	1.2 controllers.conf
	1.3 DB
2. Esquema directorios
3. Ampliaci�n de funcionalidades
	3.1 Ficheros plantilla
4. Control de la aplicaci�n
---------------------------------

1. Configuraci�n

1.1 webapp.conf
	Este archivo deber� encontrarse en el directorio ./conf
	Sus variables son:
		
	server_ip = localhost	// Bind IP
	server_port = 7777		// Bind port
	control_port = 9999		// Bind control port. Puerto de control de la apliacion, ver 4. Control de la apliaci�n.
	base_path = .\web		// Base path donde est�n ubicados los ficheros html a servir.


	log_file = .\log\webapp.log		// fichero de log
	#log_format = date time c-ip cs-mehtod cs-uri cs-bodylength x-status sc-serverMsg-s
	log_format = date time c-ip cs-mehtod cs-uri x-status	// formato de log

	#error log
	error_file = .\log\errors.log	// fichero de errores
	#error_level = LOG_ALL | ~LOG_TRACE
	error_level = LOG_ALL		// nivel de errores a mostrar

	#controller configuration archive
	controller_conf_file=.\conf\controllers.conf	// fichero de controladores din�micos
	include_path=.\includes\			// path de includes
	
1.2 controllers.conf
	En este archivo se dan de alta todas aquellas clases din�micas que el servidor WebApp crear� y le asignar� una ruta web.
	De tal manera que cuando alg�n cliente web acceda a esa URL el servidor redigir� la petici�n a la clase din�mica.
	
	Ejemplo:
	ArtList=/ArtList	// Todas las peticiones dirigidas hacia http://localhost:7777/ArtList llegar�n a la clase ArtList
						
						
1.3 DB
	Al iniciar la aplicaci�n deber� indicarse en el primer par�metro de entrada una cadena de conexi�n a base de datos que ser� usada de manera global por todos los controladores.

2. Esquema directorios
	El �nico directorio no configurable es el de configuraci�n. Deber� llamarse "conf" y estar dentro del direcotrio donde se ejecute la aplicaci�n web.
	Aparte de este directorio se necesitan al menos otros tres: uno para ficheros de inclusi�n, otro para los logs y un tercero que servir� de base para los ficheros est�ticos de la aplicaci�n web como ficheros html e im�genes.

3. Ampliaci�n de funcionalidades
	Para incluir nuevas funcionalidades al servidor web hay que crear controladores din�micos. Estos controladores son clases gen�ricas C++ que deben heredar de la clase GenericController e implementar los m�todos "classId" y "executeQuery".
	Cuando el servidor reciba una petici�n dirigida a un determinado controlador, invocar� al m�todo "executeQuery" pasando como par�metro todas las variables que hayan sido enviadas con la petici�n web(POST y GET indistintamente).
	Esta funci�n deber� devolver una estructura de respuesta que ser� enviada al cliente web. En caso de que la petici�n sea incorrecta o exista alg�n problema en la ejecuci�n se podr� devolver alguna respuesta preestablecida, ver m�todo constructNotFoundResponse. 
	IMPORTANTE: Para que la aplicaci�n web pueda instanciar objetos de los controladores, se deber� incluir la siguiente macro en el archivo de implementaci�n del controlador: REGISTER_CLASS(ClassName);
	
3.1 Ficheros plantilla
	Los ficheros plantilla permiten generar c�modamente c�digo HTML donde devolver el resultado del procesamiento de la peticiones.
	Para conocer su funcionamiento ver la documentaci�n de la clase HTMLTPage de la librer�a Stream.
	
4. Control de la aplicaci�n
	La aplicaci�n web abre un puerto de control cuyo n�mero es configurable en el archivo WebApp.conf.
	Este puerto es accesible usando un cliente Telnet cualquiera. Responde a los siguientes comandos:
	- SHUTDOWN	Finaliza la aplicaci�n.
	- RESTART	Reinicia todo el proceso de inicializaci�n.
	- NOOP		No hace nada.