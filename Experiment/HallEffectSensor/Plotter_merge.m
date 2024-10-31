tiledlayout(1,2)

% Plot the first graph (N)
nexttile
plot(merge(:,2),merge(:,1), 'DisplayName','No shield')
hold on
plot(merge(:,7), merge(:,6), 'DisplayName','shield')
ylabel("Voltage (V)");
xlabel("Distance (Cm)");
title('North')
legend('Location', 'southeast');
hold off
% Get the Y-axis limits of the first plot
ylim_N = ylim;

% Plot the second graph (S)
nexttile
plot(merge(:,4), merge(:,3), 'DisplayName','No shield')
hold on
plot(merge(:,9), merge(:,8), 'DisplayName','shield')
ylabel("Voltage (V)");
xlabel("Distance (Cm)");
title('South')
legend('Location', 'southeast');
hold off
% Invert the X-axis for the second plot
set(gca, 'XDir', 'reverse');
% Get the Y-axis limits of the second plot
ylim_S = ylim;

% Determine the common Y-axis limits based on both plots
common_ylim = [min(ylim_N(1), ylim_S(1)), max(ylim_N(2), ylim_S(2))];

% Set the same Y-axis limits for both plots
nexttile(1);
ylim(common_ylim);

nexttile(2);
ylim(common_ylim);

% Add a big title across the entire layout
sgtitle('Voltage per distance (North and south)', 'FontWeight', 'bold', 'FontSize', 14) % Big title across both plots