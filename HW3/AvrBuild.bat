@ECHO OFF
"C:\Program Files (x86)\Atmel\AVR Tools\AvrAssembler2\avrasm2.exe" -S "E:\uni\term8\AZ-Microp\HWs\HW3\labels.tmp" -fI -W+ie -C V2E -o "E:\uni\term8\AZ-Microp\HWs\HW3\program.hex" -d "E:\uni\term8\AZ-Microp\HWs\HW3\program.obj" -e "E:\uni\term8\AZ-Microp\HWs\HW3\program.eep" -m "E:\uni\term8\AZ-Microp\HWs\HW3\program.map" "E:\uni\term8\AZ-Microp\HWs\HW3\program.asm"
