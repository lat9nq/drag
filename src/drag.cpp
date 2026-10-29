#include <cmath>
#include <cstdio>
#include <limits>
#include <string>
#include <vector>

class Bullet {
  public:
    explicit Bullet(std::string name_, double drag, double caliber_mm_, double mass_grams,
                    double damage_, double muzzle_vel_, double gravity_factor_ = 1.0)
        : name{name_}, drag_coefficient{drag}, caliber_mm{caliber_mm_}, mass{mass_grams / 1000.0},
          damage{damage_}, muzzle_vel{muzzle_vel_}, gravity_factor{gravity_factor_} {
        area = std::pow(caliber_mm / 2000.0, 2.0) * M_PI;
    }
    ~Bullet() = default;

    const std::string &Name() const {
        return name;
    }

    double DragCoefficient() const {
        return drag_coefficient;
    }

    double Area() const {
        return area;
    }

    double Mass() const {
        return mass;
    }

    double Damage() const {
        return damage;
    }

    double MuzzleVel() const {
        return muzzle_vel;
    }

  private:
    std::string name;
    double drag_coefficient;
    double caliber_mm;
    double mass;
    double damage;
    double muzzle_vel;
    double area;
    double gravity_factor;
};

std::vector<Bullet> bullets{
    Bullet{"liberator 5.5x50mm FMJ", .3, 5.5, 4.5, 80, 900},
    Bullet("liberator penetrator 5.5x50mm penetrator", .3, 5.5, 4.5, 60, 1000),
    Bullet{"liberator concussive 5.5x50mm explosive", .3, 5.5, 4.5, 65, 800},
    Bullet{"tenderizer rico", .3, 8, 11, 105, 820},
    Bullet{"adjudicator battle rifle", .3, 8, 11, 95, 820},
    Bullet{"ma5c assault rifle", 0.3, 8.0, 11.0, 80.0, 820.0},
    Bullet{"diligence 9x70mm FMJ", .3, 9.0, 20.0, 165.0, 850.0},
    Bullet{"diligence counter sniper 9x70mm high velocity", .3, 9, 20, 200, 940},
    Bullet{"constitution", .3, 8.0, 20.0, 180.0, 850.0},
    Bullet{"deadeye", .3, 8.0, 20.0, 300.0, 850.0},
    Bullet{"amendment", .3, 8.0, 20.0, 200.0, 850.0},
    Bullet{"punisher 10-gauge buckshot", .5, 8, 6, 45, 385},
    Bullet{"slugger 10-gauge slug", 2.0, 18.0, 50.0, 280.0, 390.0},
    Bullet{"cookout 10-gauge flm", .8, 8, 2, 16, 120},
    Bullet{"halt 10-gauge flechette", .3, 8, 6, 35, 385},
    Bullet{"breaker 12-gauge buckshot", .5, 8, 4, 30, 360},
    Bullet{"breaker ie 12-gauge liberty fire", .8, 8, 2, 20, 120},
    Bullet{"breaker snp 12-gauge birdshot", .5, 3.0, 1.0, 15.0, 250.0},
    Bullet{"m90a shotgun buckshot", 0.5, 8.0, 6.0, 55.0, 385.0},
    Bullet{"knight 9x20mm soft metal jacket", 1.2, 9, 7, 70, 375},
    Bullet{"gallant 9x20mm HIGH VELOCITY P", 1.2, 9.0, 7.0, 65, 450},
    Bullet{"defender 12x25mm FMJ", 1.2, 12, 15, 80, 285},
    Bullet{"pummeler 12x25mm stun", 1.2, 12, 15, 70, 210},
    Bullet{"reprimand rhino", 1.2, 12, 15, 125, 285},
    Bullet{"m7s smg", 1.2, 9.0, 7.0, 70.0, 320.0},
    Bullet{"dominator 15x100mm rocket", 0, 15, 100, 275, 180},
    Bullet{"eruptor jar phoenix 20mm rocket", 0, 15, 100, 230, 180},
    Bullet{"exploding crossbow bolt explosive", 1, 15, 100, 270, 100},
    Bullet{"punisher plasma bolt", 4, 20, 100, 100, 90},
    Bullet{"purifier charge", 1.5, 20, 25, 200, 350},
    Bullet{"scorcher bolt medium", 1.5, 20, 25, 100, 550},
    Bullet{"accelerator rifle medium plasma bolt p1", 0.1, 20.0, 25.0, 250, 1000},
    Bullet("variable 9x20mm hollow point", .6, 9, 7, 85, 320),
    Bullet{"peacemaker 9x20mm hollow point", 1.2, 9, 7, 85, 320},
    Bullet{"redeemer 9x20mm FMJ", 1.2, 9, 7, 60, 375},
    Bullet{"senator 13x40mm FMJ", .3, 12, 15, 200, 550},
    Bullet{"verdict magnum", 1.2, 12, 15, 125, 285},
    Bullet{"stim pistol stim", .1, 1, 1, 0, 200},
    Bullet{"grenade pistol 40mm HEAT", 1.2, 40, 50, 250, 100},
    Bullet{"loyalist plasma small", 1, 10, 10, 150, 550},
    Bullet{"ultimatum 80mm HEAT", .5, 80, 500, 1000, 20},
    Bullet{"m6c socom pistol", 1.2, 12.0, 15.0, 100.0, 285.0},
    Bullet{"mg-43 8x60mm FMJ", .3, 8, 11, 90, 820},
    Bullet{"anti-materiel rifle 12.5x100mm EIT", .3, 12.5, 52, 450, 880},
    Bullet{"heavy machine gun 12.5x100mm BCHP", .3, 12.5, 52, 150, 980},
    Bullet{"autocannon 20mm APHET", .3, 20, 120, 260, 820},
    Bullet{"autocannon 20mm FLAK", .3, 40, 130, 150, 820},
    Bullet{"expendable anti-tank 75mm HEAT", 0, 75, 2500, 2000, 200},
    Bullet{"recoilless rifle 85mm HEAT", .3, 85, 3300, 3200, 250},
    Bullet{"recoilless rifle 85mm HE", 0, 85, 3300, 750, 250},
    Bullet{"railgun projectile", .3, 10, 50, 600, 2000},
    Bullet{"epoch cannon bolt", .1, 20, 100, 400, 250},
    Bullet{"leveller eat-411 projectille", 0.5, 80, 500, 1000, 50},
    Bullet{"grenade launcher 40mm he grenade projectile", 1.2, 40, 50, 0, 100},
    Bullet{"apex AMW-2 P", 0.10, 60.0, 70.0, 1550, 1500},
    Bullet{"breacher p-34 p", 2.0, 33.0, 100.0, 60, 150.0},
};

constexpr double air_density = 1.2;

// returns Newtons force
double Drag(const Bullet &b, double vel) {
    return 0.5 * air_density * vel * vel * b.DragCoefficient() * b.Area();
}

// return joules energy
double Energy(const Bullet &b, double vel) {
    // return vel;
    return 0.5 * b.Mass() * std::pow(vel, 2);
}

double Radians(double degrees) {
    return M_PI * degrees / 180.0;
}

constexpr double resolution = 1.0e-5; // seconds
constexpr double max_travel = 200.0;  // m
constexpr double gravity = 9.81;      // m/s^2

struct {
    double time;
    double distance_x;
    double distance;
    double drop;
    double speed;
} typedef Ballistics;

void ComputeBallistics(std::vector<Ballistics> &ballistics_table, double firing_angle_degrees,
                       const Bullet &bullet, double stride, double max_distance = max_travel) {
    double speed = bullet.MuzzleVel(); // meters/second
    double angle = Radians(firing_angle_degrees);

    double travelled = 0; // meters
    double drop = 0;      // meters
    int steps = 0;
    double print_step = 0;
    std::vector<double> table{};
    while (travelled < max_distance) {
        steps++;
        double vel_y = speed * std::sin(angle);
        double vel_x = speed * std::cos(angle);

        double drag_force = Drag(bullet, speed);
        double drag_accel = drag_force / bullet.Mass();

        double accel_y = -drag_accel * std::sin(angle) - gravity;
        double accel_x = -drag_accel * std::cos(angle);

        double vfx = vel_x + accel_x * resolution;
        double vfy = vel_y + accel_y * resolution;

        double dist_x = (vel_x + 0.5 * accel_x * resolution) * resolution;
        double dist_y = (vel_y + 0.5 * accel_y * resolution) * resolution;

        travelled += dist_x;
        drop += dist_y;

        speed = std::sqrt(vfy * vfy + vfx * vfx);
        angle = std::atan(vfy / vfx);

        if (steps * resolution > 10.0) {
            return;
        }

        double origin_distance = std::sqrt(travelled * travelled + drop * drop);

        if (origin_distance > print_step) {
            Ballistics entry;
            entry.time = steps * resolution;
            entry.distance = origin_distance;
            entry.distance_x = travelled;
            entry.drop = drop;
            entry.speed = speed;

            ballistics_table.push_back(entry);

            print_step += stride;
        }
    }
}

constexpr double tolerance = 1.0e-5; // 1 mm

void FindZero(std::vector<Ballistics> &table, double &angle, const Bullet &b, double distance) {
    double delta = 1.0;
    int attempts = 0;
    double drop = std::numeric_limits<double>::lowest();
    ComputeBallistics(table, angle, b, distance, distance);
    if (table.empty()) {
        return;
    }
    bool positive = (table.back().drop > 0);
    while (std::fabs(drop) > tolerance && attempts < 100) {
        table.clear();
        ComputeBallistics(table, angle, b, distance, distance);
        if (table.empty()) {
            return;
        }
        drop = table.back().drop;
        // printf("%.0fm,\t%.2fm,\t%d,\t%f\n", distance, drop, positive, angle);
        if (drop < 0.0) {
            if (positive) {
                positive = false;
                delta *= 0.5;
            }
            angle += delta;
        } else {
            if (!positive) {
                positive = true;
                delta *= 0.5;
            }
            angle -= delta;
        }
        attempts++;
    }
}

void ComputeZeroAngles(const Bullet &b, double stride, double distance) {
    std::vector<Ballistics> table{};
    double angle{};
    double last_travel = std::numeric_limits<double>::lowest();
    for (int i = 0; i <= distance; i += stride) {
        FindZero(table, angle, b, i);
        double adjacent = i * std::cos(Radians(angle));
        double compensated_drop = i * std::sin(Radians(angle));
        if (table.empty()) {
            continue;
        }
        // printf("%dm,\t%.2f degrees,\t(%.2f,%.2f)m\n", i, angle, adjacent, compensated_drop);
        if (adjacent < last_travel) {
            break;
        }
        last_travel = adjacent;
        printf("%.2f,%.2f\n", adjacent, compensated_drop);
    }
}

void PrintBallistics(const Bullet &b, const std::vector<Ballistics> &table) {
    const auto compute_energy = [&](double v) {
        return Energy(b, v);
        // return v;
    };
    const double muzzle_energy = compute_energy(b.MuzzleVel());
    printf("%s\n", b.Name().c_str());
    printf("SEC,\tMETERS,\tM/S,\tJOULES,\tDAMAGE,\tDROP (M)\n");

    for (const auto &entry : table) {
        double energy = compute_energy(entry.speed);
        std::printf("%.4f,\t%.2f,\t%.1f,\t%.0f,\t%.3f,\t%.3f\n", entry.time, entry.distance,
                    entry.speed, energy, entry.speed / b.MuzzleVel(), entry.drop);
    }
}

int main(int argc, char *argv[]) {

    if (argc == 1) {
        for (const Bullet &b : bullets) {
            std::vector<Ballistics> table{};
            ComputeBallistics(table, 0, b, 25);
            PrintBallistics(b, table);
            // exit(0);
        }

        return 0;
    }

    for (int i = 1; i < argc; i++) {
        for (const Bullet &b : bullets) {
            if (b.Name().find(argv[i]) != std::string::npos) {
                ComputeZeroAngles(b, 10, 1000);
                // std::vector<Ballistics> table{};
                // ComputeBallistics(table, 0, b, 5);
                // PrintBallistics(b, table);
                break;
            }
        }
    }
}