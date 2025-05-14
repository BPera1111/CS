% Parámetros
f = 100; % Frecuencia de la señal (Hz)
fs = 1000; % Frecuencia de muestreo (Hz)
t_start = 0; % Tiempo de inicio (s)
t_end = 0.5; % Tiempo final (s)

% Vector de tiempo
t = t_start:1/fs:t_end;

% Señal senoidal
y = sin(2 * pi * f * t);

% Gráfica
figure;
plot(t, y);
xlabel('Tiempo (s)');
ylabel('Amplitud');
title('Señal Senoidal de 100Hz');
grid on;