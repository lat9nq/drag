#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

class Bullet {
  public:
    explicit Bullet(std::string name_, double drag, double caliber_mm_, double mass_grams,
                    double damage_, double muzzle_vel_)
        : name{name_}, drag_coefficient{drag}, caliber_mm{caliber_mm_}, mass{mass_grams / 1000.0},
          damage{damage_}, muzzle_vel{muzzle_vel_} {
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
};

std::vector<Bullet> bullets{
    Bullet{"liberator 5.5x50mm FMJ", .3, 5.5, 4.5, 80, 900},
    Bullet("liberator penetrator 5.5x50mm penetrator", .3, 5.5, 4.5, 60, 1000),
    Bullet{"liberator concussive 5.5x50mm explosive", .3, 5.5, 4.5, 65, 800},
    Bullet{"tenderizer rico", .3, 8, 11, 105, 820},
    Bullet{"adjudicator battle rifle", .3, 8, 11, 95, 820},
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
    Bullet{"knight 9x20mm soft metal jacket", .6, 9, 7, 70, 375},
    Bullet{"defender 12x25mm FMJ", .6, 12, 15, 80, 285},
    Bullet{"pummeler 12x25mm stun", .6, 12, 15, 70, 210},
    Bullet{"reprimand rhino", .6, 12, 15, 125, 285},
    Bullet{"dominator 15x100mm rocket", 0, 15, 100, 275, 180},
    Bullet{"eruptor jar phoenix 20mm rocket", 0, 15, 100, 230, 180},
    Bullet{"exploding crossbow bolt explosive", 1, 15, 100, 270, 100},
    Bullet{"punisher plasma bolt", 4, 20, 100, 100, 90},
    Bullet{"purifier charge", 1.5, 20, 25, 200, 350},
    Bullet{"scorcher bolt medium", 1.5, 20, 25, 100, 550},
};

constexpr double air_density = 1.2;

// returns Newtons force
double Drag(const Bullet &b, double vel) {
    return 0.5 * b.Area() * vel * vel * b.DragCoefficient() * air_density;
}

// return joules energy
double Energy(const Bullet &b, double vel) {
    // return vel;
    return 0.5 * b.Mass() * std::pow(vel, 2);
}

void PrintBallistics(const Bullet &b) {
    const auto calc_energy = [&](double v) {
        return Energy(b, v);
        // return v;
    };

    constexpr double resolution = 1.0e-6; // seconds
    constexpr double max = 100.0;         // m
    const double vel_0 = b.MuzzleVel();   // m/s
    const double muzzle_energy = calc_energy(vel_0);
    constexpr int stride = 25;
    printf("%s\n", b.Name().c_str());
    printf("SEC,\tMETERS,\tM/S,\tJOULES,\tDAMAGE\n");

    int int_pos = 0;
    double current_vel = vel_0;
    u_int64_t t{};
    for (double pos = 0.0; pos < max;) {
        t++;
        const double force = Drag(b, current_vel);
        double new_vel = current_vel - force / b.Mass() * resolution;
        pos += new_vel * resolution;

        if (int_pos != std::floor(pos)) {
            int_pos = std::floor(pos);
            if (int_pos % stride == 0) {
                const auto energy = calc_energy(new_vel);
                const auto damage_proportion = new_vel / vel_0;
                // const auto damage = std::floor(energy / muzzle_energy * b.Damage());
                const auto damage = std::floor(damage_proportion * b.Damage());
                std::printf("%.03f,\t%d,\t%.2f,\t%.1f,\t%.02f\n", t * resolution,
                            static_cast<int>(std::floor(pos)), new_vel, Energy(b, new_vel),
                            damage_proportion);
            }
        }
        current_vel = new_vel;
    }
}

int main() {
    for (const Bullet &b : bullets) {
        PrintBallistics(b);
        // exit(0);
    }

    return 0;
}