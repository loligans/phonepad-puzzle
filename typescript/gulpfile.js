var spawn = require('child_process').spawnSync;

var gulp = require('gulp');
var ts = require('gulp-typescript');
var babel = require('gulp-babel');
var sourcemaps = require('gulp-sourcemaps');
var clean = require('gulp-clean');

var appTsProject = ts.createProject('tsconfig.json');

gulp.task('clean', () => {
  return gulp.src('out/**/*', {read: false}).pipe(clean());
});

gulp.task('build', ['clean'], () => {
  return appTsProject.src()
          .pipe(sourcemaps.init())
          .pipe(appTsProject())
          .js
          .pipe(babel())
          .pipe(sourcemaps.write('.'))
          .pipe(gulp.dest('out'));
});

gulp.task('start', ['build'], () => {
  return spawn('node', ['out/app.js'], {stdio: 'inherit'});
});