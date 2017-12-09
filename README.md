[![Build Status](https://travis-ci.org/cbrown1/pyin.svg?branch=master)](https://travis-ci.org/cbrown1/pyin)

# pyin

A python binding to the yin algorithm, a well-established autocorrelation based pitch algorithm. 

Read a paper on Yin here: http://audition.ens.fr/adc/pdf/2002_JASA_YIN.pdf

## Installing

### Download:

```bash
git clone https://github.com/cbrown1/pyin.git
```

### Compile and install:

```bash
python setup.py build
sudo python setup.py install
```

## Usage
```python
pitch_track = get_pitch(sig, fs)
```
