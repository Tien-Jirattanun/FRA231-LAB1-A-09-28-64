figure;
plot(HallSensor_S(:,1), HallSensor_S(:,3),'DisplayName', 'No shield');
hold on
plot(HallSensor_S_Shield(:,1), HallSensor_S_Shield(:,3),'DisplayName','Shield')
title("Magnetic sensor (South pole) (Magnetic flux per Voltage)");
xlabel("Voltage (V)");
ylabel("Magnetic flux (mT)");
legend('Location', 'southeast');
hold off

