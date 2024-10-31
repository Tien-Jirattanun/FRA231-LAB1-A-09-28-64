figure
plot(Linear_B_filter(:,2), Linear_B_filter(:,3),"DisplayName","Measurement Resistance")

hold on
plot(Linear_B_filter(:,2), Linear_B_filter(:,5), "DisplayName","Datasheet Resistance")
errorbar(Linear_B_filter(:,2), Linear_B_filter(:,5), 20, 'k', 'DisplayName', 'Error Bars')
title("Measurement resisitance ratio and Datasheet resistance ratio Per rotational ratio")
xlabel("Rotational ratio (%)")
ylabel("Resistance ratio (%)")
hold off