figure;
plot(Loadcell_one(:,2), Loadcell_one(:,1), "DisplayName","Reference mass");
hold on
title("Output voltage per reference mass(Experiment one)");
ylabel("Output voltage(V)");
xlabel("Reference mass(Kg)");
hold off

figure;
plot(Loadcell_two(:,2), Loadcell_two(:,1));
hold on
title("Output voltage per reference mass(Experiment two)");
ylabel("Output voltage(V)");
xlabel("Reference mass(Kg)");
hold off

figure;
plot(Loadcell_one(:,3), Loadcell_one(:,1));
hold on
title("Output voltage per ratio calculation mass(Experiment one)");
ylabel("Output voltage(V)");
xlabel("Ratio calculation mass(Kg)");
hold off

figure;
plot(Loadcell_two(:,3), Loadcell_two(:,1));
hold on
title("Output voltage per ratio calculation mass(Experiment two)");
ylabel("Output voltage(V)");
xlabel("Ratio calculation mass(Kg)");
hold off

figure;
plot(Loadcell_one(:,4), Loadcell_one(:,1));
hold on
title("Output voltage per graph fitting calculation mass(Experiment one)");
ylabel("Output voltage(V)");
xlabel("Graph fitting calculation mass(Kg)");
hold off

figure;
plot(Loadcell_two(:,4), Loadcell_two(:,1));
hold on
title("Output voltage per graph fitting calculation mass(Experiment two)");
ylabel("Output voltage(V)");
xlabel("Graph fitting calculation mass(Kg)");
hold off

figure;
plot(Loadcell_one(:,3), Loadcell_one(:,2));
hold on
title("Reference mass per ratio calculation mass(Experiment one)");
ylabel("Reference mass(Kg)");
xlabel("Ratio calculation mass(Kg)");
hold off

figure;
plot(Loadcell_two(:,3), Loadcell_two(:,2));
hold on
title("Reference mass per ratio calculation mass(Experiment two)");
ylabel("Reference mass(Kg)");
xlabel("Ratio calculation mass(Kg)");
hold off

figure;
plot(Loadcell_one(:,4), Loadcell_one(:,2));
hold on
title("Reference mass per graph fitting calculation mass(Experiment one)");
ylabel("Reference mass(Kg)");
xlabel("Graph fitting calculation mass(Kg)");
hold off

figure;
plot(Loadcell_two(:,4), Loadcell_two(:,2));
hold on
title("Reference mass per graph fitting calculation mass(Experiment two)");
ylabel("Reference mass(Kg)");
xlabel("Graph fitting calculation mass(Kg)");
hold off

figure;
plot(Loadcell_one(:,2), Loadcell_one(:,1), "DisplayName","Reference mass");
hold on
plot(Loadcell_one(:,3), Loadcell_one(:,1), "DisplayName","Ratio calculation mass");
plot(Loadcell_one(:,4), Loadcell_one(:,1), "DisplayName","Graph fitting calculation mass");
title("Output voltage per mass(Experiment one)");
ylabel("Output voltage(V)");
xlabel("Mass(Kg)");
legend("Location","southeast");
hold off

figure;
plot(Loadcell_two(:,2), Loadcell_two(:,1), "DisplayName","Reference mass");
hold on
plot(Loadcell_two(:,3), Loadcell_two(:,1), "DisplayName","Ratio calculation mass");
plot(Loadcell_two(:,4), Loadcell_two(:,1), "DisplayName","Graph fitting calculation mass");
title("Output voltage per mass(Experiment two)");
ylabel("Output voltage(V)");
xlabel("Mass(Kg)");
legend("Location","southeast");
hold off