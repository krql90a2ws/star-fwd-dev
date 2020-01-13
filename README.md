# star-fwd-dev

Development environment for the STAR Forward tracking package (inside StRoot)

## Setup
Clone the repo:
```sh
git clone https://github.com/jdbrice/star-fwd-dev.git
cd star-fwd-dev
```

Now, make sure the submodules are initialized:
```sh
git submodule update --init --recursive
```

## Running the forward tracking code
Launch a (docker) development environment with:
```sh
./dev.sh
```
This will drop you into a docker container with the current path of `/tmp/work/` where work is you local `work` directory mounted into the container. Before running the code, setup the STAR environment variables:
```sh
source star_env
```
  

Now you can run the code with:
```sh
root4star -b -q -l simple.C
```
  
This will produce an output called `results.root` with histograms etc.

## Modifying and building
The code lives in `star-sw/StRoot/StgMaker/` so you can edit the code here.  
After making changes you can rebuild the code with:
```sh
./build
```
If compilation succeeds then the code is updated.
  
## Forward Tracking Configuration
The forward tracking code is driven by a configuration file `work/config.xml` :
You can modify this file to change the configuration of the ForwardTrack maker.

Example configuration and some information about the various parts below:
```xml
<?xml version="1.0" encoding="UTF-8"?>
<config>

	<!-- The below line is still needed, do not change for now -->
	<Input url="SimHitsTuple_1track_0p2_5.root" type="sim_mc" max-events="200" first-event="0" si="false" />

	<!-- This is the output file for the QA ROOT file produced by the tracking code -->
	<Output url="results.root" />

	<!-- CONFIGURATION for Track finding -->
	<TrackFinder nIterations="1">
		<Iteration> <!-- Options for first iteration -->
			<SegmentBuilder>
				<Criteria name="Crit2_RZRatio" min="0.9" max="1.11" />
				<Criteria name="Crit2_DeltaPhi" min="0" max="10" />	
				<Criteria name="Crit2_DeltaRho" min="-5" max="20"/>
				<Criteria name="Crit2_StraightTrackRatio" min="0.9" max="1.1"/>
			</SegmentBuilder>

			<ThreeHitSegments>
				<Criteria name="Crit3_3DAngle" min="0" max="90" />
				<Criteria name="Crit3_PT" min="0" max="100" />
				<Criteria name="Crit3_ChangeRZRatio" min="0" max="1.01" />
				<Criteria name="Crit3_2DAngle" min="0" max="2" />
			</ThreeHitSegments>
		</Iteration>

		<!-- These are used if not defined inside <Iteration> -->
		<ThreeHitSegments>
			<Criteria name="Crit3_2DAngle" min="0" max="50" />
		</ThreeHitSegments>

		<Connector distance="1"/>

		<SubsetNN active="true" min-hits-on-track="4" >
			<Omega>0.99</Omega>
			<StableThreshold>0.001</StableThreshold>
		</SubsetNN>	

		<HitRemover active="true">
		</HitRemover>

	</TrackFinder>

	<!-- CONFIGURATION for Track Fitting -->
	<TrackFitter constB="true" display="false" noMaterialEffects="true" >
		<Vertex sigmaXY="0.01" sigmaZ="5" includeInFit="true" />
		
		<!-- for MC only -->
		<Hits sigmaXY="0.01" useFCM="true" />
	</TrackFitter>


</config>

```


## Generating simulated hits
The above code expects simulated hits available in the file `testg.fzd`. 
If you need to generate simulation input, you can use the project here: https://github.com/jdbrice/star-fwd-sim  




