<?php global $base_url; ?>
<div class="col-sm-12 col-md-12 advance-log-message">
	<form class="well form-horizontal" action="" method="post"  id="verification_form">
		<fieldset>
				<!-- Logo --> 
		<div class="logo">
			<a href="<?php echo $base_url ; ?>"><img src="/<?php print $directory;?>/img/logo.png"></a>
		</div>

		<!-- Form Name -->
		<legend class="text-center"><?php print $msg_title ?></legend>

		<!-- Message Before -->
		<div class="body-message">
		  <div class="col-md-12"> <?php print $msg_before; ?> </div>  
		</div>

		<!-- Text input-->

		<div class="form-group">
		  <div class="col-lg-12"> Name </div>  
		  <div class="col-lg-12 inputGroupContainer">
		  	<div class="input-group">
		  		<span class="input-group-addon"><i class="glyphicon glyphicon-user"></i></span>
		  		<input id="" name="" placeholder="Membership name" class="form-control"  type="text">
		    </div>
		  </div>
		</div>

		<div class="form-group">
		  <div class="col-lg-12"> Membership number </div>  
		  <div class="col-lg-12 inputGroupContainer">
		  	<div class="input-group">
		  		<span class="input-group-addon"><i class="glyphicon glyphicon-lock"></i></span>
		  		<input id="vId" name="v_id" placeholder="Provide membership number" class="form-control"  type="text">
		    </div>
		  </div>
		</div>

		<!-- Error Message --> 
		<div class="error-message">
			<div class="text-center error-text">

			</div>
		</div>

		<!-- Message Body -->
		<div class="body-message">
		  <div class="col-md-12"> <?php print $msg_body ?> </div>  
		</div>

		<!-- Button -->
		<div class="form-group">
		  <div class="col-md-12">
		    <button type="submit" class="btn" >Send <span class="glyphicon glyphicon-send"></span></button>
		  </div>
		</div>

		</fieldset>
	</form>
</div>
