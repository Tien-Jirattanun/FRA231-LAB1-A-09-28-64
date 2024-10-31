tiledlayout(1,2)

% Plot the first graph (N)
nexttile
plot(merge_flux(:,1),merge_flux(:,2), 'DisplayName','No shield')
hold on
plot(merge_flux(:,6), merge_flux(:,7), 'DisplayName','shield')
ylabel("Magnetic flux density (mT)");
xlabel("Distance (Cm)");
title('North')
legend('Location', 'southeast');
hold off
% Get the Y-axis limits of the first plot
ylim_N = ylim;

% Plot the second graph (S)
nexttile
plot(merge_flux(:,3), merge_flux(:,4), 'DisplayName','No shield')
hold on
plot(merge_flux(:,8), merge_flux(:,9), 'DisplayName','shield')
ylabel("Magnetic flux density (mT)");
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
sgtitle('Magnetic flux density per distance (North and south)', 'FontWeight', 'bold', 'FontSize', 14) % Big title across both plots