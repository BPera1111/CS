% num=1;
% den=[1 -1/2 2];
% zplane(num,den);
% title('Pole-Zero Plot of H(z) = 1/(1-1/3z^-1)');

% Ejemplo 1: Filtrado de una señal con un filtro paso bajo
% b = [0.2 0.2 0.2 0.2 0.2]; % Coeficientes del numerador
% a = 1; % Coeficiente del denominador
% x = randn(1, 100); % Señal de entrada (ruido blanco)
% y = filter(b, a, x); % Señal filtrada
% figure;
% subplot(2,1,1);
% plot(x);
% title('Señal de entrada');
% subplot(2,1,2);
% plot(y);
% title('Señal filtrada');

% % Ejemplo 2: Filtrado de una señal con un filtro paso alto
% b = [1 -1]; % Coeficientes del numerador
% a = [1 -0.95]; % Coeficientes del denominador
% x = sin(2*pi*(0:99)/10) + randn(1, 100)*0.1; % Señal de entrada (senoidal con ruido)
% y = filter(b, a, x); % Señal filtrada
% figure;
% subplot(2,1,1);
% plot(x);
% title('Señal de entrada');
% subplot(2,1,2);
% plot(y);
% title('Señal filtrada');

% EJ 2 % Convolución de dos señales
% x1 = [1 1 3];
% x2 = [1 0 3];
% x_conv = conv(x1,x2)

% x_fil = filter(x1, 1, x2) % Filtrado de la señal x2 con el filtro x1 lo que simula la convolución
%                           % No muestra la convolución completa, dado que filter devuelve la señal de la misma longitud que señal de entrada
                          
% x2_ext = [x2, zeros(1, length(x1)-1)];
% x_fil = filter(x1, 1, x2_ext)
                          
% % EJ 3 % Función de trasnferencia
% b = 1;              % coeficientes del numerador (X(z))
% a = [1 -0.7];       % coeficientes del denominador (Y(z))
% x = [1 zeros(1,20)];  % impulso delta
% y = filter(b, a, x);
% stem(0:20, y)
% title('Respuesta al impulso')

% x = ones(1, 21);    % escalón unitario
% y = filter(b, a, x);
% stem(0:20, y)
% title('Respuesta al escalón')


% ej5
% Coeficientes del sistema
b = 1;                        % Numerador (X(z))
a = [1 -0.5 -0.1 -0.2];       % Denominador (Y(z))

% Señal de entrada: escalón
x = ones(1, 30);              % u[n] hasta n=29

% Condiciones iniciales: y[-1], y[-2], y[-3]
yini = [1 2 3];

% Inicialización con filtic
zi = filtic(b, a, yini);      % Devuelve estado inicial del filtro

% Filtrado con condiciones iniciales
y = filter(b, a, x, zi);

% Gráfico
stem(0:29, y)
xlabel('n'); ylabel('y[n]')
title('Respuesta del sistema con condiciones iniciales')
