#!/bin/bash
files=$(find -type f | egrep "\.[15].scd$")

for file in $files; do

	if [[ ${file} != *.scd ]]; then
		mv ${file} ${file}.scd
		echo "move ${file} to ${file}.scd "
	fi
done

for file in $files; do

	dst=/usr/local/share/man/man1/${file//*"/"/}

	dst=${dst//".scd"/}.gz

	if [[ -e ${dst} ]]; then
		rm ${dst}
		echo "move ${dst}"
	fi

	if [[ $file == *.1.scd && ! -e ${dst} ]]; then
		echo "dst = ${dst}"
		gzip -c $file | sudo tee ${dst} >/dev/null
		echo "create archive from file ${file} and to ${dst}"
	fi

	dst=/usr/local/share/man/man5/${file//*"/"/}
	dst=${dst//".scd"/}.gz

	if [[ -e ${dst} ]]; then
		rm ${dst}
		echo "move ${dst}"
	fi

	if [[ $file == *.5.scd && ! -e ${dst} ]]; then
		echo "dst = ${dst}"

		gzip -c $file | sudo tee ${dst} >/dev/null

		echo "create archive from file ${file} and to ${dst}"
	fi

done

#for file in $files; do
#
#	dst=/usr/local/share/man/man1/${file//*"/"/}.gz
#
#	if [[ $file == *.1 && ! -e ${dst} ]]; then
#		gzip -c $file | sudo tee ${dst} >/dev/null
#	fi
#
#	dst=/usr/local/share/man/man5/${file//*"/"/}.gz
#
#	if [[ $file == *.5 && ! -e ${dst} ]]; then
#		gzip -c $file | sudo tee ${dst} >/dev/null
#	fi
#done
