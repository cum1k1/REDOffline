/** @file SumOfIntegral.hh
    @brief Defines the SumOfIntegral data class
    @author rsaldanha
    @ingroup daqroot
    @ingroup modules
*/

#ifndef SUMOFINTEGRAL_h
#define SUMOFINTEGRAL_h

#include "Rtypes.h" //has the classdef macro
#include <vector>
#include <iostream>

/** @class SumOfIntegral
    @brief Stores information relevant to the sum of single scintillation event across all channels
    @ingroup modules
    @ingroup daqroot
*/
class SumOfIntegral{
public:
    SumOfIntegral() { Clear(); }
    virtual ~SumOfIntegral() {  }
    void Clear();
    void Print(int pulse);
public:
    Int_t start_index;      ///< index marking the start of the pulse
    double start_time;    ///< time since trigger at start of pulse
    Int_t end_index;        ///< index for the end of the pulse
    double end_time;      ///< time since trigger at end of pulse
    bool start_clean;     ///< start of pulse does not overlap with previous
    bool end_clean;       ///< end of pulse does not overlap with next or window
    double dt;            ///< Time between the start of this pulse and the next one (or end of trigger)

    bool saturated;       ///< was the pulse saturated on any channel?
    double npe;                   ///< integral scaled for single pe amplitude
    std::vector <double> f_param; ///< f-parameters for different time values
    double f90;                   ///< f-parameter for 90 ns
    double f90_fixed;             ///< f-parameter for 90 ns over fixed_time1
    double fixed_npe1;            ///< integral evaluated at fixed_time1
    double fixed_npe2;            ///< integral evaluated at fixed_time2
    bool fixed_npe1_valid;        ///< did the event extend at least past fixed_time1?
    bool fixed_npe2_valid;        ///< did the event extend at least past fixed_time2?

    Int_t max_chan;                 ///< channel which had the highest number of p.e.
    double max_chan_npe;             ///< no of p.e. on channel which had the highest number of p.e.

    bool is_s1;          ///< true = S1 pulse
    bool is_s2;          ///< true = S2 pulse

    double gatti;        ///< Gatti parameter for electron and nuclear recoil templates
    double ll_ele;       ///< Log-likelihood for electron recoil template
    double ll_nuc;       ///< Log-likelihood for nuclear recoil template
    double ll_r;         ///< Log-likelihood ratio of nuclear to electron recoil template


    ClassDef(SumOfIntegral,2);
};

inline void SumOfIntegral::Clear()
{
    saturated = false;
    start_index = -1;
    start_time = 0;
    end_index = -1;
    end_time = 0;
    npe = 0;
    f_param.clear();
    f90 = 0;
    f90_fixed = 0;
    gatti = 0;
    ll_ele = 0;
    ll_nuc = 0;
    ll_r = 0;
    fixed_npe1 = 0;
    fixed_npe2 = 0;
    fixed_npe1_valid = false;
    fixed_npe2_valid = false;
    dt = -1;
    is_s1 = false;
    is_s2 = false;
    start_clean = false;
    end_clean = false;
    max_chan = -1;
    max_chan_npe = 0;
};

inline void SumOfIntegral::Print(int pulse)
{ ; }

#endif
